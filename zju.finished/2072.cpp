#include<iostream>
using namespace std;

unsigned long long M, N;

void fun(){
    unsigned long long t, pred = 0;
    int i;
    while(N > 0 && pred != M){
        N--;
        t = 1;
        for(i=63; i>=0; i--){
            if(M & (t<<i)){
                break;
            }
        }
        // skdjfie
        pred = M;
        M &= ~(t<<i);
        M *= 2;
        ++M;
    }
    cout<<M<<endl;
}

int main(){     
    while(cin>>M>>N){
        fun();
    }
    return 0;
}

