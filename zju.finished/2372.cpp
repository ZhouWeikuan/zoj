#include<iostream>
using namespace std;
enum {
    SIZ = 100008,
};
struct Node{
    char name[20];
    int a, b, v;
    bool operator < (const Node&o) const {
        if(v!=o.v) return v<o.v;
        return strcmp(name, o.name)<0;
    }
};
int num, F, T;
Node agen[108];
char buf[100];

void conv(Node&o){
    char *p = index(buf, ':');
    *p = 0; p++;
    strcpy(o.name, buf);
    sscanf(p,"%d,%d",&o.a,&o.b);
}
void operate(Node &o){
    o.v = 0;
    int p, t;
    for(p=F,t=F/2; t>=T; p=t,t/=2){
        if((p-t)*o.a < o.b){
            o.v += (p-t)*o.a;
        } else {
            o.v += o.b;
        }
    }
    o.v += (p-T)*o.a;
}
void fun(){
    int i;
    for(i=0; i<num; i++){
        operate(agen[i]);
    }
    sort(agen, agen+num);
    for(i=0; i<num; i++){
        printf("%s %d\n", agen[i].name, agen[i].v);
    }
}
void readIn(){
    scanf("%d%d%d ",&F,&T,&num);
    for(int i=0; i<num; i++){
        fgets(buf, 100, stdin);
        conv(agen[i]);
    }
}
int main(){
    int tst, tn=0;
    scanf("%d", &tst);
    while(tst--){
        printf("Case %d\n", ++tn);
        readIn();
        fun();
    }
    return 0;
}

