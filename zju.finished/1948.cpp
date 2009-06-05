#include<cstdio>
#include<queue>
#include<map>
#include<set>
#include<deque>

using namespace std;
map<int,int> team;
set<int> table;
deque<int> tque[1004];
queue<int> wait;
int num;

void scanTeam(){
	int t = num;
	int n,a,q = 0;
	while(t --){
		scanf("%d ",&n);
		while(n--){
			scanf("%d ",&a);
			team[a] = q;
		}
		q++;
	}
}
void fun(){
	char cmd[20];
	int name,t;
	
	scanf("%s",cmd);
	while(cmd[0]!='S'){
		if(cmd[0]=='E'){
			scanf("%d ",&name);
			t = team[name];
			if(table.find(t) == table.end()){
				table.insert(t);
				wait.push(t);
			}
			tque[t].push_back(name);
		}else{
			t = wait.front();
			name = tque[t].front();
			tque[t].erase(tque[t].begin());
			printf("%d\n",name);
			if(tque[t].size()==0){
				wait.pop();
				table.erase(t);
			}
		}
		scanf("%s",cmd);
	}
	
	while(wait.size()){
		t = wait.front(); wait.pop();
		tque[t].clear();
	}
	
	team.clear();
	table.clear();
}

int main(){
	int tstcase = 0;

	scanf("%d ",&num);
	while(num){
		scanTeam();
		printf("Scenario #%d\n",++tstcase);
		fun();
		printf("\n");

		scanf("%d ",&num);
	}

	return 0;
}
