#include<iostream>

using namespace std;
enum {
	N = 120,
};
int rank[N];
int input[N],num;

void init(){
	for(int i=0;i<N;i++){
		rank[i] = N-i;
	}
}
int fun(){
	int *a = &rank[N-num];
	int i,j;
	j = 0; i = num - input[j];
	i++,j++;
	while(i<num){
		if(input[j] >= a[i]){
			j++,i++;
		} else {
			i = num - input[j];
			i++,j++;
		}
	}
	return num-j;
}

int main(){
	init();

	cin>>num;
	while(num){
		for(int i=0;i<num;i++){
			cin>>input[i];
		}
		cout<<fun()<<endl;
		cin>>num;
	}
	return 0;
}
