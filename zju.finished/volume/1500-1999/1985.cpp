#include<cstdio>
using namespace std;

//利用Bar形图的特点，在O(N)的时间内求出N个点的左右界限 
enum {
	Size = 100004,
};
struct Node {
    int h;
    int l,r;
};
int testcase, num;
Node tree[Size];
int sum[Size],top;

void fun(){
	int i,t;
    tree[0].h = tree[num + 1].h = -1;
    
    //求左边的界限位置 
	top = 0;
	sum[top] = 0;
	for(i=1;i<=num;i++){
        while( tree[sum[top]].h >= tree[i].h){
            top--;
        }
        tree[i].l = sum[top] + 1;
        sum[++top] = i;
	}
	//求右边的界限位置 
    top = 0;
    sum[top] = num + 1;
    for(i=num;i>=1;i--){
        while(tree[sum[top]].h >= tree[i].h){
            top --;
        }
        tree[i].r = sum[top] -1;
        sum[++top] = i;
    }
    //计算面积 
    long long ret, ans = 0;
    for(i =1;i<=num;i++){
        ret = tree[i]. r - tree[i].l + 1;
        ret *= tree[i].h;
        if(ret > ans)
            ans = ret;
    }
    printf("%lld\n", ans);
    //printf("%I64d\n", ans);
}

int main(){

	scanf("%d ", &num);
	while(num > 0){
		for(int i=1;i<=num;i++){
			scanf("%d ", &tree[i].h);
		}
        fun();

		scanf("%d ", &num);
	}

	return 0;
}

