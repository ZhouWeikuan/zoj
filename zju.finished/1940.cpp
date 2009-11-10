#include<iostream>
#include<queue>
#include<vector>
#include<set>

using namespace std;
struct Comp {
	int operator()(int a, int b){		
		return a>>15 >= b>>15;
	}	
};

char matrix[32][32][32];
int L,R,C;
int sl, sr, sc;

void insert(set<int> &tab, priority_queue<int, vector<int>, Comp > & q, int a, int b, int c, int lvl){
	if(a<0||b<0||c<0 ||a>=L|| b>= R ||	c>= C){
		return;
	}	
	if(matrix[a][b][c] == 1)
		return;
		
	int key = (a<<10) + (b<<5) + c;
	if(tab.find(key) != tab.end())
		return;
	tab.insert(key);
	key += (lvl<<15);
	q.push(key);
}

void fun(){
	int key = (sl <<10) + (sr <<5) + sc;
	int level;
	int i,j,k;
    priority_queue<int, vector<int>, Comp > que;
    set<int> table;
    
    table.insert(key);
    que.push(key);
    while(! que.empty()){
		key = que.top();
		que.pop();
		level = key >>15;
		i = (key>>10) &0x1f;
		j = (key>>5) &0x1f;
		k = (key) &0x1f;
		if(matrix[i][j][k] == 2){
			cout<<"Escaped in "<< level << " minute(s)."<<endl;
			return;
		}
		level ++;
		insert(table,que, i-1,j,k, level);
		insert(table,que, i+1,j,k, level);
		insert(table,que, i,j-1,k, level);
		insert(table,que, i,j+1,k, level);
		insert(table,que, i,j,k-1, level);
		insert(table,que, i,j,k+1, level);
	}
    cout<<"Trapped!"<<endl;
}

int main(){
    int i,j,k;
    char ele;
    int t;
        
    cin>>L>>R>>C;
    while(L){
    	for(i=0;i<L;i++){
			for(j=0;j<R;j++){
				for(k=0;k<C;k++){
					cin>>ele;
					if(ele == 'S'){
						sl = i;
						sr = j;
						sc = k;
						t = -1;
					} else if(ele=='E') {
						t = 2;
					} else if( ele=='.'){
						t = 0;
					} else {
						t = 1;
					}
					matrix[i][j][k] = t;
				}
			}
		}
		fun();
		
		cin>>L>>R>>C;
	}
    
    return 0;
}
