#include<iostream>
using namespace std;
enum {
    SIZ = 20,
};

bool mark[1<<SIZ];
int N;

int inline getPtr(int p){
    return p/2 + (p%2)*N/2;
}

void dfs(int p){
    while(!mark[p]){
        mark[p] = true;
        p = getPtr(p);
    }
}

int count(FILE *fp){
    memset(mark, false, sizeof(mark));
    fprintf(fp, "digraph {\n");
    int ret = 0;
    for (int i=0; i<N; ++i){
        fprintf(fp, "%d -> %d\n", i, getPtr(i));
        if (mark[i]) continue;
        dfs(i);
        ret ++;
    }
    fprintf(fp, "}\n");
    return ret;
}

void fun(){
    int i, n;
    char buf[20];
    for (n=1; n<SIZ; ++n){
        sprintf(buf, "%d.dot", n);
        FILE*fp = fopen(buf, "w");
        N = 1<<n;
        i = count(fp);
        printf("%d %d %d\n", n, i, (2+(N-2)/n));
        fclose(fp);
    }
}

void readIn(){
}

int main(){

    //while(readIn() > 0){
        fun();
    //}

    return 0;
}

