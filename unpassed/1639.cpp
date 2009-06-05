#include<iostream>
#include<set>
// TLE
using namespace std;
enum {
    SIZ = 1<<16,
};
struct Node {
    int s;
    char name[12];
};
Node prog[18];
struct cmp{
    bool operator()(const int &a, const int &b)const{
        return strcmp(prog[a].name, prog[b].name)<0;
    }
};
int num, cn;
int ptr[18];
unsigned score[SIZ];
unsigned con[1040];
unsigned cur;

void setup(int v){
    int i, t;
    for(i=0, t=1; i<num; i++, (t<<=1)){
        if(v & t){
            score[v] += prog[ptr[i]].s;
        }
    }
}

void dfs(unsigned m){
    set<unsigned > s;
    set<unsigned >::iterator it;
    s.insert(m);
    int i; unsigned t;
    while(!s.empty()){
        it = s.end();
        --it;
        m = *it;
        s.erase(it);
        score[cur | m] = -1;
        for(i=0,t=1; i<num; (t<<=1), ++i){
            if(m & t){
                s.insert(m&~t);
            }
        }
    }
}

void fun(){
    memset(score, 0, sizeof(score));
    int i, m=(1<<num) - 1;
    for(i=0; i<cn; i++){
        cur = con[i];
        dfs((~cur) & m);
    }
    int maxV = 0;
    m = 1<<num;
    for(i=0; i<m; i++){
        if(score[i] == -1) continue;
        setup(i);
        if(score[i] != -1 && score[i] > maxV){
            maxV = score[i];
        }
    }
    printf("%d\n", maxV);
}

int search(char *s){
    int l=0, h=num, m;
    int t;
    while(l < h){
        m = (l+h)/2;
        t = strcmp(prog[ptr[m]].name, s);
        if(t < 0){
            l = m + 1;
        } else if(t > 0){
            h = m;
        } else {
            return m;
        }
    }
    return l;
}

void parse(char *s, int p){
    con[p] = 0;
    s = strtok(s, " \n");
    int t;
    while(s){
        t = search(s);
        con[p] |= (1<<t);
        s = strtok(NULL, " \n");
    }
}

int readIn(){
    scanf("%d", &num);
    if(num==0) return 0;
    for(int i=0; i<num; i++){
        ptr[i] = i;
        scanf("%s%d", &prog[i].name, &prog[i].s);
    }
    sort(ptr, ptr+num, cmp());
    scanf("%d ", &cn);
    static char buf[1000];
    for(int i=0; i<cn; i++){
        fgets(buf, 1000, stdin);
        parse(buf, i);
    }
    return num;
}
int main(){
    int tst = 1;
    while(readIn()>0){
        printf("System %d: ", tst++);
        fun();
    }
    return 0;
}

