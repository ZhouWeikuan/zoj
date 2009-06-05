#include<iostream>
#include<string.h>
using namespace std;
enum {
    SIZ = 26,
};
int num;
int gn, tn; // guess count, score
int in[SIZ];
int cnt[SIZ];
char buf[2000];

void fun(){
    int i;
    double v;
    for(i=0; i<SIZ; i++){
        if(in[i]==0) continue;
        v = 2.0 * in[i] * gn / tn;
        printf("%c %.2lf\n", 'A'+i, v);
    }
}
void test(int cur, int b, int c){
    int t = abs(cnt[b]-c);
    ++gn;
    if(t==0){
        in[cur] += 2;
        tn += 2;
    }else if(t==1){
        ++in[cur];
        ++tn;
    }
}
void parse(int cur){
    char *p = strtok(buf, ",");
    while(p!=NULL){
        test(cur, *p-'a', atoi(p+2));
        p = strtok(NULL,",");
    }

}
int readIn(){
    if(fgets(buf, 2000, stdin) == NULL) return 0;
    memset(cnt, 0, sizeof(cnt));
    memset(in, 0, sizeof(in));
    gn = tn = 0;
    do {
        for(int i=0; buf[i]!='\n'; ++i){
            ++cnt[buf[i]-'a'];
        }
        fgets(buf, 2000, stdin);
    }while(isalpha(buf[0]));
    num = atoi(buf);
    char cur;
    for(int i=0; i<num;i++){
        scanf(" %c ", &cur);
        cur -= 'A';
        fgets(buf, 2000, stdin);
        parse((int)cur);
    }
}
int main(){
    int tst=0;
    while(readIn() > 0){
        if(tst++)printf("\n");
        fun();
    }
    return 0;
}

