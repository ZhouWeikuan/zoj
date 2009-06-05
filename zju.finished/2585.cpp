#include<cstdio>
#include<cstring>

using namespace std;
enum {
    SIZ = 100,
};
char buf[SIZ];
int  tree[2][26];
int pos;

int calc(int n){
    int t,i;
    int *ptr = tree[n];
    for( i=0;buf[i]!=0 && buf[i] !='\n';i++){
        t = buf[i] -'a';
        ptr[t]++;
    }
    pos += i;
}

int fun(){
    int s = 0,t;
    for(int i=0;i<26;i++){
        t = tree[0][i];
        if(t > tree[1][i])
            t = tree[1][i];
        s += t;
    }
    s *= 2;
    return pos-s;
}

int main(){
    int tstnum, tstcase = 0;

    scanf("%d ",&tstnum);
    while(tstcase ++ < tstnum){
        pos = 0;
        memset(tree, 0, sizeof(tree));
        fgets(buf, SIZ, stdin);
        calc(0);
        fgets(buf, SIZ, stdin);
        calc(1);

        printf("Case #%d:  %d\n", tstcase, fun());
    }

	return 0;
}
