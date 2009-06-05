#include<iostream>
#include<vector>
// Wrong Answer
using namespace std;
enum {
    SIZ = 10,
    ADD = 0,
    DIV,
    DUP,
    MUL,
    SUB,
    LIM,
};
const char *str[5] = {
    "ADD", "DIV", "DUP", "MUL", "SUB"
};
vector<int> dat; // dat in the stack;
vector<int> op;  // operations;
vector<int> sav; // saved operations.
int in[SIZ], out[SIZ], num;

typedef void (*func)(int, int);
void add(int a, int b){
    dat.push_back(a+b);
}
void Div(int a, int b){
    dat.push_back(b/a);
}
void dup(int a, int b){
    dat.push_back(b);
    dat.push_back(a);
    dat.push_back(a);
}
void mul(int a, int b){
    dat.push_back(a*b);
}
void sub(int a, int b){
    dat.push_back(b-a);
}
int cond[5] = {
    2,2,1,2,2,
};
func fun[5]  = {
    add, Div, dup, mul, sub
};
bool check(){
    bool state = true;
    int j, a, b;
    vector<int> sd = dat;
    for(int i=1; i<num; i++){
        dat.clear();
        dat.push_back(in[i]);
        dat.push_back(in[i]);
        for(j=1; j<op.size(); j++){
            if(op[j] == DUP){
                dat.push_back(dat.back());
                continue;
            }
            a = dat.back(); dat.pop_back();
            b = dat.back(); dat.pop_back();
            if(op[j] == DIV && (a==0||b%a!=0)){
                state = false;
                goto end;
            }
            (fun[op[j]])(a, b);
        }
        if(dat[0] != out[i]){
            state = false;
            break;
        }
    }
 end:
    dat = sd;
    return state;
}
void update(){
    int i;
    if(sav.size()!=0 && sav.size() < op.size()) return;
    if(sav.size() == op.size()){
        for(i=0; i<op.size(); i++){
            if(sav[i] < op[i])
                return;
        }
    }
    sav = op;
}
void test(int d){
    if(dat.size()== 1 && dat[0]==out[0]){
        if(check()){
            update();
        }
    }
    if(d>=10 || dat.size() >11 - d) return;
    if(dat.size() == 1){ // only dup
        op.push_back(DUP);
        dat.push_back(dat.back());
        test(d+1);
        op.pop_back();
        dat.pop_back();
        return;
    }
    int a, b, l, j;
    a = dat.back(); dat.pop_back();
    b = dat.back(); dat.pop_back();
    for(int i=0; i<LIM; i++){
        if(i==DIV && a == 0)
            continue;
        op.push_back(i);
        (fun[i])(a, b);
        test(d+1);
        dat.pop_back();
        if(i == DUP){
            dat.pop_back();
            dat.pop_back();
        }
        op.pop_back();
    }
    dat.push_back(b);
    dat.push_back(a);
}
void proc(){
    dat.clear();
    op.clear();
    sav.clear();

    dat.push_back(in[0]);
    dat.push_back(in[0]);
    op.push_back(DUP);
    test(1);
}

int readIn(){
    int i;
    scanf("%d", &num);
    if(num == 0) return 0;
    for(i=0; i<num; i++){
        scanf("%d", &in[i]);
    }
    for(i=0; i<num; i++){
        scanf("%d", &out[i]);
    }
    for(i=0; i<num; i++){
        if(in[i]!=out[i])
            return 1;
    }
    return 2;
}
int main(){
    int tst=1, t;
    while( (t=readIn())>0 ){
        printf("Program %d\n", tst++);
        if(t == 2){
            printf("Empty sequence\n\n");
        } else {
            proc();
            if(sav.size() == 0 ){
                printf("Impossible\n\n");
            } else {
                for(t=0; t<sav.size(); t++){
                    printf("%s%s", t?" ":"", str[sav[t]]);
                }
                printf("\n\n");
            }
        }
    }
    return 0;
}

