#include<cstdio>
#include<vector>
#include<utility>

using namespace std;

int signum, validnum,transnum;
int nodenum;
int tree[4096];

vector< pair<int,int> > matrix[16][12];

int travel(int node, int signal){
	int child;	
	
	vector< pair<int,int> > &vec = matrix[signal][tree[node]];
	vector< pair<int,int> >::iterator iter;
	
	child = node *2 + 1;
	if(child >= nodenum || tree[child] ==-1 ){ /* Leaf node */
		for(iter = vec.begin(); iter!= vec.end(); iter++){
			if(iter->first >= validnum && iter->second >= validnum)
				return 1;
		}
		
		return 0;
	}
	
	for(iter = vec.begin(); iter!= vec.end(); iter++){
		if(travel(child, iter->first) && travel(child + 1, iter->second ) )
			return 1;
	}
	
	return 0;
}

void fun(){
    int level;
    int i;
    char alpha;
    
    scanf("%d ", &level);
    while(level != -1){
		nodenum = 1<<(level+1);
		nodenum--;
		for(i=0;i<nodenum;i++){
			scanf("%c ", &alpha);
			if(alpha == '*'){
				tree[i] = -1;
			} else {
				tree[i] = alpha -'a';
			}
		}
		
		if(travel(0,0)){
			printf("Valid\n");
		} else {
			printf("Invalid\n");
		}
		
		scanf("%d ", &level);
	}
}

int main(){
    int i,j,a,b;
    char end;
    int tstcase = 0;
    
    scanf("%d %d %d ", &signum, &validnum, &transnum);
    while(signum ){
		validnum = signum - validnum;
		for(i=0;i<signum;i++){
			for(j=0;j<transnum;j++){
				matrix[i][j].clear();
				do {
					scanf("%d %d%c", &a,&b,&end);
					matrix[i][j].push_back( make_pair(a,b) );
				} while(end != '\n');				
			}			
		}
		if(tstcase ++){
			printf("\n");
		}
		printf("NTA%d:\n", tstcase);
		
		fun();
		
		scanf("%d %d %d ", &signum, &validnum, &transnum);
	}
    
    return 0;
}
