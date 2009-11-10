#include<cstdio>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

typedef struct {
	int value;
	int parent;
	int freq;
} Node ;

char input[1000];
int pos,num;
set<int> tree[60];

void buildtree(int p){
	int k;
	while(input[pos] != '(')
		pos ++;
	pos ++;
	k = 0;
	while(input[pos] ==' '){
		pos ++;
	}
	while(input[pos] <= '9' && input[pos] >= '0'){
		k *= 10;
		k += input[pos] -'0';
		pos ++;
	}
	if(p!=0){
		tree[p].insert(k);
		tree[k].insert(p);
	}
	
	num ++;

	while(input[pos] !=')'){
		while(input[pos] ==' ')
			pos ++;
		if(input[pos] =='(')
			buildtree(k);
	}
	pos ++;
}

void fun(){
	int i,k;
	int print = 0;
	priority_queue<int, vector<int>, greater<int> > q;
	set<int>::iterator iter;
	for(i=1;tree[i].size();i++){
		if(tree[i].size() ==1){
			q.push(i);
		}		
	}

	k = num;
	while(k-- > 1){
		i = q.top(); q.pop();
		iter = tree[i].begin();
		tree[*iter].erase(i);
		if(tree[*iter].size()==1){
			q.push(*iter);
		}
		tree[i].clear();

		i = *iter;
		if(print ){
			printf(" %d",i);
		} else {
			printf("%d", i);
			print = 1;
		}
	}
	printf("\n");

}

int main(){
	int tstcase;
	int root,i;
	char c;

	fgets(input, 1000, stdin);
	while(!feof(stdin)){
		num = pos = 0;
		buildtree(0);

		fun();
		
		fgets(input, 1000, stdin);
	}	

	return 0;
}
