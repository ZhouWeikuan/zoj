#include<cstdio>

/*
 *  是树状！
 */
using namespace std;
enum {
    SIZ = 1004,
};
int N,M;
int par[SIZ];
void init(){
    for(int i=0;i<N;i++){
        par[i] = i;
    }
}
int get_par(int x){
    int p = par[x];
    while(p != par[p]){
        p = par[p];
    }
    par[x] = p;
    return p;
}
int in_same(int a, int b){
    a = get_par(a);
    b = get_par(b);
    if(a == b) 
        return 1;
    return 0;
}

void con(int a, int b){
    a = get_par(a);
    b = get_par(b);
    if(a < b){
        par[b] = a;
    } else {
        par[a] = b;
    }
}

int fun(){
    int a,b;
    while(M --){
        scanf("%d%d", &a, &b);
        if(in_same(a,b)){
            goto end;
        }
        con(a,b);
    }
    return 1;
end:
    while(M --){
        scanf("%d%d", &a, &b);
    }
    return 0;
}

int main(){
    int a,b;
    int istree;
    const char *ans[2] = {
        "No",
        "Yes"
    };
    scanf("%d%d",&N,&M);
    while(N){
        istree = 1;
        if(M == N - 1){
            init();
            istree = fun();
        } else {
            while(M --){
                scanf("%d%d",&a,&b);
            }
            istree = 0;
        }
        printf("%s\n", ans[istree]);

        scanf("%d%d",&N,&M);
    }

	return 0;
}
