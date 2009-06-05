#include<cstdio>
#include<cstring>

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
    h[0] = h[N+1] = -1;
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

void process(){
    int j;
    char ch;
    for(j=1;j<=N;j++){
        scanf("%c ", &ch);
        if(ch == 'R'){
            h[j] = 0;
        } else {
            h[j] ++;
        }
    }
    calc();
}

void fun(){
    int i;
    for(i=0;i<M;i++){
        process();
    }
}

int main(){
    scanf("%d", &K);
    while(K --){
        val = 0;
        scanf("%d%d ", &M, &N);
        memset(h, 0, sizeof(h));
        h[N+1] = h[0] = -1; 
        fun();
        val *= 3;
        printf("%d\n", val);
    }

	return 0;
}
