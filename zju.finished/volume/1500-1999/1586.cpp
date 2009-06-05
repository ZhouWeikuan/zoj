#include<iostream>
#include<queue>
using namespace std;

int qs[1008];
int num;
struct Node {
	int key;
	int val;
};
int comp(const Node *a, const Node *b){
	return a->val - b->val;
}

Node que[1000008];

void init(){
	for(int i=0;i<num;i++)
		qs[i] = i;
}

int parent (int k){
	int n = k;
	int t = qs[k];
	while(t != k){
		k = t;
		t = qs[k];
	}
	qs[n] = t;
	return t;
}

int disjoin(int a, int b){
	int pa = parent(a);
	int pb = parent(b);

	if(pa == pb){
		return 0;
	}
	if(pa > pb){
		qs[pa] = pb;
		pa = pb;
	}else {
		qs[pb] = pa;
	}
	qs[a] = qs[b] = pa;
	return 1;
}

void fun(){
	int i,j;
	int edge =0 ;
	Node *p;

	for(i=0;i<num;i++){
		for(j=0;j<num;j++){
			p = &que[edge];
			scanf("%d", &p->val);
			if(j==i)
				continue;
			p->key = (i<<16) + j;
			p->val += qs[i] + qs[j];
			edge++;
		}
	}

	qsort(que, edge, sizeof(Node), (int(*)(const void*,const void*))comp);
	init();
	num--;
	int cost = 0;
	int k = 0;
	while(num > 0){
		const Node &n = que[k];
		i = n.key >>16; j=n.key&0x0ffff;
		if(disjoin(i,j)){
			num--;
			cost += n.val;
		}
		
		k++;
	}
	cout<<cost<<endl;
}

int main(){
	int tstcase;
	scanf("%d",&tstcase);

	while(tstcase --){
		scanf("%d",&num);
		for(int i=0; i<num; i++)
			scanf("%d",&qs[i]);
		
		fun();		
	}

	return 0;
}
