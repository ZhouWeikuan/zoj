#include<iostream>

using namespace std;
enum {
    SIZ = 3000,
};

unsigned int save[SIZ];
unsigned int a,b;

unsigned fun(unsigned big, unsigned small){
    unsigned i,j;
    for(i=0;i<=big;i++)
        save[i] = 1;
    for(j=1;j<=small;j++){
        for(i=1;i<=big;i++){
            save[i] += save[i-1];
/*            if(save[i] < save[i-1]){
                cerr<<"overflow... "<<i <<" "<<j<<endl;
            } */
        }
    }
    return save[big];
}

int main(){
    unsigned t;
    
    cin>>a>>b;
    while(a + b){
        if(a > b){
            t = a; a = b; b = t;
        }
        if(a==0){
            cout<<1<<endl;
        } else if(a ==1){
            cout<<(b+1)<<endl;
        } else if(a == 2){
            if(b % 2 ==0){
                t = (b+2)/2;
                t *= (b+1);
            } else {
                t = (b+1)/2;
                t *= (b+2);
            }
            cout<<t<<endl;
        } else {
            t = fun(b,a);
            cout<<t<<endl;
        }
        
        cin>>a>>b;
    }

	return 0;
}
