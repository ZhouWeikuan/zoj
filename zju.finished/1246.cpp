#include<iostream>
#include<vector>
using namespace std;
// Wrong Answer
struct Node {
    int c, e; // c是系数, e是指数
    bool operator<(const Node&rhs)const{
        return e>rhs.e;
    }
};
char buf[100];

void output(vector<Node> &pro){
    if(pro.size() == 0){
        printf("0\n");
        return;
    }
    for(int i=0; i<pro.size(); i++){
        if(i) printf("+");
        if(pro[i].e >= 2){
            if(pro[i].c > 1){
                printf("%d*",pro[i].c);
            }
            printf("n^%d", pro[i].e);
        }else if(pro[i].e == 1){
            if(pro[i].c > 1){
                printf("%d*",pro[i].c);
            }
            printf("n");
        } else {// e == 0
            printf("%d", pro[i].c);
        }
    }
    printf("\n");
}
void update_e(vector<Node> &v){
    for(int i=0; i<v.size(); i++){
        v[i].e++;
    }
}
void update_c(int t, vector<Node> &v){
    for(int i=0; i<v.size(); i++){
        v[i].c *= t;
    }
}
void combine(vector<Node> &r){
    vector<Node> v;
    Node one;
    scanf("%s", buf);
    while(buf[0] != 'E'){
        if(strcmp(buf, "LOOP") == 0){
            scanf("%s", buf);
            v.clear();
            if(buf[0] == 'n'){ // affect e
                combine(v);
                update_e(v);
            } else { // affect c
                int t = atoi(buf);
                combine(v);
                update_c(t, v);
            }
            while(v.size()){
                r.push_back(v.back());
                v.pop_back();
            }
        } else { // OP
            scanf("%s", buf);
            one.c = atoi(buf);
            one.e = 0;
            r.push_back(one);
        }
        scanf("%s", buf);
    }
    sort(r.begin(), r.end());
    int i=0, s=0;
    for( ; s<r.size(); s++){
        if(r[s].c == 0) continue;
        if(i == 0 || r[s].e != r[i-1].e){
            r[i++] = r[s];
        } else {
            r[i-1].c += r[s].c;
        }
    }
    while(r.size() > i){
        r.pop_back();
    }
}
int main(){
    int tst=0, tstnum;
    vector<Node> pro;
    scanf("%d", &tstnum);
    while(tst++ < tstnum){
        scanf("%s", buf);
        printf("Program #%d\nRuntime = ", tst);
        pro.clear();
        combine(pro);
        output(pro);
        printf("\n");
    }
    return 0;
}

