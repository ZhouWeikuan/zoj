#include<iostream>

using namespace std;

enum {
	Size = 501,
};

int sum[Size] = {0,1};

void init(){
    int i;
    int t;
    for(i=2;i<Size;i++){
		if(i%2 ==0){
			t = i/2;
			t *= t;
		} else {
			t  = (i*i -1) /4;			
		}		
		sum[i] = sum[i-1] + (i+1) * i / 2 + t;
	}
}

int main(){
    int n;
    
    init();
	
	while(cin>>n){
		cout<< sum[n] << endl;		
	}
    
    return 0;
}
