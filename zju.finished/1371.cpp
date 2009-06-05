#include<iostream>
using namespace std;
// 为了提交这个，WA了五次，考虑不周的地方太多了...
enum {
    SIZ = 10008,
};
int num; // number of ordinal
int most; // biggest cost
int cur;  // current ordinal
int top; // position of next ordinal to be printed
int s, e; // smallest: s, biggest: e;
int cnt[SIZ];
int ord[SIZ];
bool small;

void add(){
    int v;
    scanf("%d", &v);
    cnt[v]++;
    if(s > e){
        s = e = v;
    } else {
        s = min(s, v);
        e = max(e, v);
    }
}
int getVal(){
    int v;
    if(s > e){
        return -1;
    }
    v = (small?s:e);
    cnt[v]--;
    for(; s<=e&&cnt[s]==0; s++)
        ;
    for(; e>=s&&cnt[e]==0; e--)
        ;
    return v;
}
void remove(){
    int v = getVal();
    if(top < num && (cur++ == ord[top])){
        printf("%d\n", v);
        top++;
    }
}
void fun(){
    char op;
    small = true;
    scanf(" %c", &op);
    while(op != 'e'){
        if(op=='a'){
            add();
        } else if(op=='r'){
            remove();
        }else if(op =='p'){
            int t;
            scanf("%d", &t);
            small = (t==1);
        }
        scanf(" %c", &op);
    }
}

int readIn(){
    if(scanf("%d", &most) < 0) return 0;
    int i;
    cur = 1;
    top = 0;
    scanf("%d", &num);
    for(i=0; i<num; i++){
        scanf("%d", &ord[i]);
    }
    for(i=0; i<= most; i++){
        cnt[i] = 0;
    }
    s = SIZ, e = -1;
    return 1;
}
int main(){
    int tst=0;
    while(readIn() > 0){
        if(tst++) printf("\n");
        fun();
    }
    return 0;
}

