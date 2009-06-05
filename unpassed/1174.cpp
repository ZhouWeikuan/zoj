// SIGSEGV

#include<cstdio>
#include<map>
#include<vector>
#include<string>
#include<cstring>

using namespace std;
struct Node {
	int ptr;
	char sp;
};
map<string, vector<int> > table;
int num;
char word[108][8];
Node output[1000008];

char st[8];
int top,cur;

void getIndex(int start, int full){
	if(top == full){
		st[full] = 0;
		string s(st);
		table[st].push_back(cur);
		return ;
	}
	for(int i = start; word[cur][i];i++){
		st[top++] = word[cur][i];
		getIndex(i+1,full);
		top --;
	}
}

void genIndex(int s){
	int len = strlen(word[s]);
	int i;
	cur = s;
	for(i=1;i<=len;i++){
		top = 0;
		getIndex(0,i);
	}
}
int fun(){
	char buf[10], ch;
	int len;
	bool exit = false;
	int pnum = 0;
	for(;exit == false;){
		scanf("%s%c",buf,&ch);
		len = strlen(buf);
		if(buf[len-1] == '#'){
			exit = true;
			buf[--len] = 0;
			ch = '\n';
		}
		string s(buf);
		map<string, vector<int> >::iterator it = table.find(s);
		if(it->second.size() > 1){
			return -1;
		}
		output[pnum].ptr = it->second[0];
		output[pnum].sp  = ch;
		pnum ++;
	}
	for(int i=0;i<pnum;i++){
		printf("%s%c", word[output[i].ptr], output[i].sp);
	}
	return 0;
}

int main(){
	int tstnum,i,t;
	scanf("%d ", &tstnum);
	while(tstnum --){
		table.clear();
		scanf("%d ",&num);
		for(i=0;i<num;i++){
			scanf("%s ",&word[i]);
			genIndex(i);
		}
		t = fun();
		if(t < 0){
			printf("AMBIGUITY\n");
		} else {
			for(i=0;i<t;i++){
				printf("%s%c",word[output[i].ptr], output[i].sp);
			}
		}
		if(tstnum)
			printf("\n");
	}

	return 0;
}
