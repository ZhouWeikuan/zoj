#include<iostream>

using namespace std;
enum {
    SIZ = 1001,
};
int C[SIZ] = {2,3};

// a > b
int gcd(int a, int b){
    int t;
    while(b){
        t = a% b;
        a = b;
        b = t;
    }
    return a;
}

void init(){
    int i,t;
    int k;
    
    for(i=2;i<SIZ;i++){
        t = C[i-1];
        for(k=1;k<i;k++){
            if( gcd(i,k) > 1)
                continue;
            t += 2;
        }
        C[i] = t;
    }
}

int main(){
    init();
    int tstnum, tstcase = 0;
    int n;

    cin>>tstnum;
    while(tstcase ++ < tstnum){
        cin>>n;
        cout<<tstcase<<" "<<n<<" "<<C[n]<<endl;
    }


	return 0;
}
