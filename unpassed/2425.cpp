#include<cstdio>
//TLE
using namespace std;
enum {
	Size = 50004,
	//Size = 50,
};
int tab[Size];
int perm[Size];
int act[Size];
int next;
struct Node {
	int ptr;
	int left,right;
};
Node tree[Size];
int get(){
	tree[next].left = tree[next].right = 0;
	return next++;
}
void Node_init(){
	next = 1;
	tree[0].left = tree[0].right = 0;
	tree[0].ptr = 0;
	act[0] = perm[0];
}
void insert(int cur, int i){
	int p = tree[cur].ptr;
	if(perm[p] > perm[i]){
		if(tree[cur].left == 0){
			int q = get();
			tree[cur].left = q;
			tree[q].ptr = i;
			act[i] = perm[i];
		} else {
			insert(tree[cur].left, i);
		}
	} else {
		if(tree[cur].right ==0){
			int q = get();
			tree[cur].right = q;
			tree[q].ptr = i;
			act[i] = perm[i];
		} else {
			insert(tree[cur].right,i);
		}
	}
	if(perm[p] <= perm[i]){
		act[i] ++;
	}
}
int N,M;

void init(){
	for(int n=2;n<Size;n++){
		tab[n] = n * (n-1)/2;
	}
}
void guess(int cur, int lim){
	if(cur == N)
		return ;
	int dif = N-cur-1;
	if(lim < tab[dif]){
		perm[cur] = 1;
	} else {
		perm[cur] = lim - tab[dif] + 1;
		lim -= perm[cur] -1;
	}
	guess(cur+1,lim);
}

void output(){
	Node_init();
	printf("%d",perm[0]);
	for(int i=1;i<N;i++){
		insert(0,i);
		printf(" %d", act[i]);
	}
	printf("\n");
}

int main(){
	init();

	scanf("%d%d",&N,&M);
	while(N > 0){
		guess(0,M);
		output();
		scanf("%d%d",&N,&M);
	}

	return 0;
}
