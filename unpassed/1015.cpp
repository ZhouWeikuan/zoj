#include<cstdio>
/*
	假设A与B相连，每点均与自己相连，则与A相连的所有点必和与B相连所有点一致。	
	经过平摊分析，算法复杂度为O(n^2) 或者说是 O(M);
	
	但是提交后结果为WrongAnswer
*/

using namespace std;
enum {
    MaxNode = 1004,
};
struct Point {
    unsigned short a;
    unsigned short b;
};
int N,M;
char mask[MaxNode][MaxNode];
Point edge[500*MaxNode];
int conn[MaxNode];

void clearAll(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            mask[i][j] = 0;
        }
    }
}

void readIn(){
    int a,b;
    int i;
    for(i=0;i<M;i++){
        scanf("%d %d ",&a,&b);
        a--, b--;
        edge[i].a = a;
        edge[i].b = b;
        mask[a][b] = 1;
        mask[b][a] = 1;
    }
    for(i=0;i<N;i++){
        mask[i][i] = 1;
        conn[i] = i;
    }
}
int getParent(int a){
    int p = conn[a];
    int t = conn[p];
    while(p != t){
        p = t;
        t = conn[p];
    }
    conn[a] = t;
    return t;
}

int cmp(int a, int b){
    for(int i=0;i<N;i++){
        if(mask[a][i] != mask[b][i]){
            return 1;
        }
    }
    return 0;
}

int fun(){
    int a,b,pa,pb;
    for(int i=0;i<M;i++){
        a = edge[i].a; 
        b = edge[i].b;
        pa = getParent(a);
        pb = getParent(b);
        if(pa != pb){
            if(cmp(a,b) != 0){
                return 1;
            }
            if(pa < pb){
                conn[pb] = pa;
            } else {
                conn[pa] = pb;
            }
        }
    }

    return 0;
}

int main(){
    char *ans[2] = {"Perfect","Imperfect"};
    scanf("%d %d ", &N, &M);
    while(N){
        readIn();
        int t = fun();
        printf("%s\n\n", ans[t]);

        clearAll();
        scanf("%d %d ", &N, &M);
    }

	return 0;
}
