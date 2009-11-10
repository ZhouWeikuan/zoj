#include<iostream>

using namespace std;
enum {
	N = 328,
};
int t[N];
int w[N];
void init(){
	int i;
	t[0] = 0;
	for(i=1;i<N;i++){
		t[i] = t[i-1] + i;
	}
	for(i=1;i<N-1;i++){
		t[i] = i * t[i+1]; 
	}
	w[0] = 0;
	for(i=1;i<N-1;i++){
		w[i] = w[i-1] + t[i];
	}
}

int main(){
	init();
	int num;
	int k,i;
	cin>>num;
	for(i=0;i<num;i++){
		cin>>k;
		cout<<i+1<<" "<<k<<" "<<w[k]<<endl;
	}

	return 0;
}
