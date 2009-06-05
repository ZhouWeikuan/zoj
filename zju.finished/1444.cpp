#include<iostream>
#include<map>

using namespace std;
enum {
    SIZ = 10002,
};

struct Node {
	int num;
	int time;
	char name[32];
	int problem[102];
    bool operator<(const Node&rhs)const{
        if(num !=rhs.num) return num>rhs.num;
        if(time != rhs.time) return time<rhs.time;
        return strcasecmp(name, rhs.name)<0;
    }
};
struct scmp{
    bool operator()(const char *a, const char*b)const {
        return strcasecmp(a,b)<0;
    }
};

map<const char *, int, scmp> table;
map<const char *, int, scmp>::iterator iter;
Node team[SIZ];
int tnum,pnum;
int data[SIZ];
struct cmp_int{
    bool operator()(const int&a, const int&b)const{
        return team[a]<team[b];
    }
};

int main(){
	int t,no;
	int cur,i;
	char buf[32];
    char s[32];
    scanf("%d",&pnum);
	i = tnum = 0;
	
	while(scanf("%d%s%d%s", &t, s, &no, buf) > 0){
		iter = table.find(s);
		if(iter == table.end()){
            cur = tnum++;
			team[cur].num = team[cur].time = 0;
            strcpy(team[cur].name, s);
            table.insert(make_pair(team[cur].name, cur));
		} else {
			cur = iter->second;
		}
        if(team[cur].problem[no] < 0) // prevent re-submit
            continue;
		++team[cur].problem[no];
		if(strcmp(buf, "AC") == 0){
			if(++team[cur].num==1){
				data[i++] = cur;
			}
			team[cur].time += t + (team[cur].problem[no]-1)*20;
            team[cur].problem[no] = -1;
		}
	}
	t = i;
	if(t <=0)
		return 0;
	sort(data,data+t, cmp_int());
	printf("%-10d%-30s%-10d%d\n",1,team[data[0]].name,
			team[data[0]].num, team[data[0]].time);
	for(i=1;i<t;i++){
		if(team[data[i-1]].num==team[data[i]].num 
				&& team[data[i-1]].time==team[data[i]].time )
			printf("%-10s"," ");
		else
			printf("%-10d",i+1);
		printf("%-30s%-10d%d\n",team[data[i]].name,
			team[data[i]].num, team[data[i]].time);
	}
	
	return 0;
}

