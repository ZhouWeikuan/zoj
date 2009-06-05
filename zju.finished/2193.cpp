#include<iostream>
#include<set>
#include<queue>
// 拓扑排序，先确实每个点的可能值，再建立拓扑序
using namespace std;

struct Node {
    int level;
    set<int> ptr;
};
int matrix[4][4];
set<int> cover[4][4];
Node tree[10];

void init(){
    int t = 1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cover[i][j].insert(t);
            cover[i+1][j].insert(t);
            cover[i][j+1].insert(t);
            cover[i+1][j+1].insert(t);
            t++;
        }
    }
}
void predo(){
    for(int i=1;i<10;i++){
        tree[i].level = 0;
        tree[i].ptr.clear();
    }
}
void setup(int x,int y, int v){
    for(set<int>::iterator it=cover[x][y].begin();
            it!=cover[x][y].end();++it){
        if(*it == v)
            continue;
        if(tree[v].ptr.find(*it) == tree[v].ptr.end()){
            tree[*it].level ++;
            tree[v].ptr.insert(*it);
        }
    }
}
int fun(){
    int i,j,t;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            cin>>t;
            setup(i,j,t);
        }
    }
    int left = 9;
    queue<int> q;
    for(i=1;i<10;i++){
        if(tree[i].level ==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        t = q.front(); q.pop();
        left--;
        for(set<int>::iterator it=tree[t].ptr.begin();
                it!=tree[t].ptr.end(); ++it){
            if(--tree[*it].level==0){
                q.push(*it);
            }
        }
    }
    return left;
}
int main(){
    init();
	char buffer[16];
	int t;
	cin>>buffer;
	while(strcmp(buffer,"ENDOFINPUT")!=0){
        predo();
		t = fun();
		if(t==0 ){
			cout<<"THESE WINDOWS ARE CLEAN"<<endl;
		}else {
			cout<<"THESE WINDOWS ARE BROKEN"<<endl;
		}		
		cin>>buffer; // for END
		
		cin>>buffer;
	}
	
	return 0;
}
