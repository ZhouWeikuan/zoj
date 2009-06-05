#include<iostream>
#include<queue>
#include<cctype>
using namespace std;
enum {
    COL = 30,
    SIZ = 108,
};
char col[COL][SIZ];
int pos[COL];
char buf[SIZ];
char KEY[COL];
int key[COL], klen;

struct Node {
    int l;
    char alp;
    bool operator<(const Node&rhs) const{
        return rhs.alp<alp;
    }
};
void shift(){
    int i;
    Node one;
    priority_queue<Node, vector<Node> > q;
    for(i=0;KEY[i];i++){
        one.l = i; one.alp = KEY[i];
        q.push(one);
    }
    i = 0;
    while(!q.empty()){
        one = q.top(); q.pop();
        key[i++] = one.l;
    }
}
void readIn(){
    scanf("%s %s", &KEY,buf);
    klen = strlen(KEY);
    int len = strlen(buf);
    int r = len % klen;
    int l = len / klen;
    for(int i=0;i<klen;i++){
        pos[i] = l;
        if(i < r)
            pos[i]++;
    }
    shift();
}
void fun(){
    int i, p = 0, t;
    for(i=0;i<klen;i++){
        t = key[i];
        strncpy(col[t], &buf[p], pos[t]);
        p += pos[t];
    }
    memset(key, 0, sizeof(key));
    t = 0;
    while(key[t] < pos[t]){
        printf("%c",tolower(col[t][key[t]]));
        key[t]++;
        t++;
        if(t>= klen)
            t = 0;
    }
    printf("\n");
}
int main(){
    int tstcase;
    scanf("%d",&tstcase);
    while(tstcase--){
        readIn();
        fun();
    }

    return 0;
}
