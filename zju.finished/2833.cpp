#include<iostream>

using namespace std;
enum {
	SIZ = 100004,
};
struct Node {
	int par;
	int num;
};
int N,M;
Node tree[SIZ];

void init(){
	for(int i = 1; i <= N; i++){
		tree[i].par = i;
		tree[i].num = 1;
	}
}

int getPar(int p){
	int t = tree[p].par;
	while(t != tree[t].par) {
		t = tree[t].par;
	}
	tree[p].par = t;
	return t;
}

void conn(int a, int b){
	a = getPar(a);
	b = getPar(b);
	if(a == b){
		;
	} else if(a < b){
		tree[b].par = a;
		tree[a].num += tree[b].num;
	} else { // a > b
		tree[a].par = b;
		tree[b].num += tree[a].num;
	}
	
}

int fun(){
	char op;
	int a,b;
	init();
	while( M --){
		scanf("%c ", &op);
		if(op == 'M'){
			scanf("%d%d ", &a, &b);
			conn(a,b);
		} else {
			scanf("%d ", &a);
			a = getPar(a);
			printf("%d\n", tree[a].num);
		}
	}
	return 0;
}

int main(){
  	int tstcase  = 0;
    while( scanf("%d%d ", &N, &M) > 0){
		if(tstcase )
			printf("\n");
		printf("Case %d:\n", ++tstcase );
		fun();
	}
    return 0;
}
