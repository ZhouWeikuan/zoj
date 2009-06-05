#include<cstdio>
//最长递增子序列
using namespace std;
enum {
	Size = 40004,
};
int testcase, num;
int tree[Size];
int sum[Size],top;

int find(int low,int high, int v){
	if(high <= low)
		return -1;
	int mid;
	while(low < high){
		mid = (low + high)/2;
		if(sum[mid] < v){ //lower
			low = mid + 1;
		} else { //higher
			high = mid;
		}
	}
	while(sum[mid] > v){
		mid--;
	}
	while(sum[mid] < v){
		mid++;
	}
	return mid;
}

int fun(){
	int i,t;
	top = -1;
	sum[++top] = tree[0];
	for(i=1;i<num;i++){
		if(sum[top] < tree[i]){
			sum[++top] = tree[i];
		} else {
			t = find(0,top+1, tree[i]);	
			sum[t] = tree[i];
		}
	}
	return ++top;
}

int main(){

	scanf("%d ",&testcase);
	while(testcase--){
		scanf("%d ", &num);
		for(int i=0;i<num;i++){
			scanf("%d ", &tree[i]);
		}
		printf("%d\n", fun());
	}

	return 0;
}
