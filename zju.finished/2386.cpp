#include<iostream>

using namespace std;
enum {
	N = 500008,
};
int dat[N];
int rev[N];
int num;
int *now, *prev;
unsigned long long ret = 0llu;

void mergesort(int a, int b, int m, int n){
	int i=0,j=0,k=0;
	int *t= &now[a];
	int *first = &prev[a];
	int *second = &prev[b];
	while(i< m && j < n){
		if(first[i] < second[j]){
			t[k] = first[i];
			i++;
		} else {
			t[k] = second[j];
			ret += m-i;
			j++;
		}
		k++;
	}
	while(i< m){
		t[k++] = first[i++];
	}
	while(j < n){
		t[k++] = second[j++];
	}
}

void merge(int n){
	int range = 2,diff=1;
	int start, *t;
	while(n >= range){
		start = 0;
		while(start +range <= n){
			mergesort(start,start+diff,diff,diff);
			start += range;
		}
		if(start + diff <= n){
			mergesort(start,start+diff,diff,n-start-diff);
		} else {
			mergesort(start,0,n-start,0);
		}
		t = now;
		now = prev;
		prev = t;

		diff = range;
		range *= 2;
	}
	mergesort(0,diff,diff,n-diff);
	
}

int main(){
	int i;

	scanf("%d",&num);
	while(num){
		for(i=0;i<num;i++){
			scanf("%d", &dat[i]);
		}
		now = rev, prev = dat;
		ret = 0;
		merge(num);
		cout<<ret<<endl;
		scanf("%d",&num);
	}

	return 0;
}
