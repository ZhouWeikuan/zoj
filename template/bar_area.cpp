#include<iostream>

using namespace std;
enum {
    SIZ = 1004,
};
int K,M,N;
int  h[SIZ];
int  l[SIZ];
int  r[SIZ];
int  s[SIZ], top;
int val;

void calc(){
    int i;
    top = 0; s[top] = 0;
    for(i=1;i<=N;i++){
        while(h[s[top]] >= h[i]){
            top --;
        }
        l[i] = s[top] + 1;
        s[++top] = i;
    }

    top = 0; s[top] = N + 1;
    for(i=N;i>=1;i--){
        while(h[s[top]] >= h[i]){
            top --;
        }
        r[i] = s[top] -1 ;
        s[++top] = i;
    }
    int t;
    for(i=1;i<=N;i++){
        t = r[i] - l[i] + 1; 
        t *= h[i];
        if(t > val)
            val = t;
    }
}

