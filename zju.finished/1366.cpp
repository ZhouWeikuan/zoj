#include<iostream>
#include<queue>
// 动态规划，注意优化 
using namespace std;
enum {
    SIZ = 100004,
};
struct Node {
	int count;
	int score;
};
Node tree[12];
int cmp(const Node *a, const Node*b){
	return -a->score + b->score;
}
int sum[12];
int money, num, part;
int mask[10][SIZ] = {0};
int tstcase = 0;

void calc(int s, int cur){
    if(part < s)
        part = s;
    if(cur == num)
        return ;
    if(mask[cur][s] >= tstcase)
        return;
    if(s + sum[cur] <= money){
        if(part < s + sum[cur])
            part = s + sum[cur];
        return;
    }
    if(part == money)
        return;
    mask[cur][s] = tstcase;
    int ns = s - tree[cur].score;
    for(int i=0; i<=tree[cur].count; i++){
        ns += tree[cur].score;
        if(ns > money)
            break;
        calc(ns, cur+1);
    }

}

int fun(){
	int i;
	part = 0;
	qsort(tree,num,sizeof(Node),( int(*)(const void*,const void*))cmp);
    memset(mask, 0, sizeof(mask));
	sum[num] = 0;
	for(i=num-1;i>=0;i--){
		sum[i] = sum[i+1] + tree[i].count * tree[i].score;
	}
	calc( 0, 0);
	return part;
}

int main(){
	int i,j;
	
	while(cin>>money>>num){
        ++ tstcase;
		j = 0;
		for(i=0;i<num;i++){
			cin>>tree[j].count>>tree[j].score;
			if(tree[j].count && tree[j].score){
				j++;
			}
		}
		num = j;

		if(money && num){
			cout<<fun()<<endl;
		} else {
			cout<<0<<endl;
		}
	}

	return 0;
}
