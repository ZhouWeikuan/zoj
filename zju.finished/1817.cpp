#include<iostream>
#include<vector>
// 中缀转后缀后再按真值表比较
using namespace std;
enum {
    SIZ = 2000,
    LPAR= 30,
    OR  = 31,
    XOR,
    AND,
    NOT,
};
int prio(char c){
    switch(c){
    case'(':
        return LPAR;
    case')':
        return 29;
    case '~':
        return NOT;
    case '&':
        return AND;
    case '^':
        return XOR;
    case '|':
        return OR;
    }
    return 0;
}
struct Node{
    vector<int> v;
};

Node tab[2];
char buf[SIZ];
int alp[30], num, cur;

bool test(const Node &o){
    vector<int> v;
    int a, b;
    for(int i=0; i<o.v.size(); i++){
        switch(o.v[i]){
        case AND:
            b = v.back(); v.pop_back();
            a = v.back(); v.pop_back();
            a &= b;
            v.push_back(a);
            break;
        case OR :
            b = v.back(); v.pop_back();
            a = v.back(); v.pop_back();
            a |= b;
            v.push_back(a);
            break;
        case XOR:
            b = v.back(); v.pop_back();
            a = v.back(); v.pop_back();
            a ^= b;
            v.push_back(a);
            break;
        case NOT:
            a = v.back(); v.pop_back();
            a = !a;
            v.push_back(a);
            break;
        default:
            a = o.v[i];
            if(a < 0){
                a = -a;
                a = alp[a];
                a = ((1<<a)&(cur))!=0;
                a = 1 - a;
            } else {
                a = alp[a];
                a = ((1<<a)&(cur))!=0;
            }
            v.push_back(a);
            break;
        }
    }
    if(v.size()!=1){
        printf("ERROR!\n");
        exit(0);
    }
    return v[0];
}

int fun(){
    int i;
    num = 0;
    for(i=0; i<30; i++){
        if(alp[i] == -1) continue;
        alp[i] = num++;
    }
    int lim = 1<<num;
    for(cur=0; cur<lim; ++cur){
        if(test(tab[0]) != test(tab[1])){
            return 0;
        }
    }
    return 1;
}

bool pred(int a, int b){
    return (b == NOT && a > b)|| ( b!=NOT && a>=b );
}

void mid2suff(char *s, int e, Node &o){
    vector<int> op;
    o.v.clear();
    int t;
    for(int i=0;i<e;i++){
        if(s[i] == ' ') continue;
        if(isalpha(s[i])){
            t = s[i] - 'a';
            alp[t] = 0;
            o.v.push_back(t);
        } else if(s[i]==')'){
            while(op.back()!= LPAR){
                o.v.push_back(op.back());
                op.pop_back();
            }
            op.pop_back();
        } else {// other operators
            t = prio(s[i]);
            if(s[i]=='('){
                op.push_back(t);
            } else {
                while(!op.empty() && pred(op.back(), t)){
                    o.v.push_back(op.back());
                    op.pop_back();
                }
                op.push_back(t);
            }
        }
    }
    while(!op.empty()){
        o.v.push_back(op.back());
        op.pop_back();
    }
}
int parse(char *s){
    int i;
    bool bin=false;
    for(i=0; s[i]; i++){
        if(s[i]==' ' || s[i] ==')') continue;
        if(bin){
            if(s[i]!='&'
                && s[i]!='^'
                && s[i]!='|' ){
                break;
            } else {
                bin = false;
            }
        } else{
            if(isalpha(s[i])){
                bin = true;
            }
        }
    }
    return i;
}

void readIn(){
    memset(alp, -1, sizeof(alp));
    fgets(buf, SIZ, stdin);
    int p = parse(buf);
    mid2suff(buf, p, tab[0]);
    int e = parse(&buf[p]);
    mid2suff(&buf[p], e, tab[1]);
}

int main(){
    int tst, tn=0;
    const char *ans[2] = {
        "Different","Equivalent"
    };
    scanf("%d ", &tst);
    while(tn++ < tst){
        printf("Data set %d: ", tn);
        readIn();
        printf("%s\n", ans[fun()]);
    }
    return 0;
}

