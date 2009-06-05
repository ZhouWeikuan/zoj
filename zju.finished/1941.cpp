#include<iostream>
#include<vector>
using namespace std;
enum {
    SIZ = 108,
};
struct Node {
    int m, s;  // m*x + s
};
Node res;
char buf[SIZ];

int getPrior(char op){
    switch(op){
    case '+':
    case '-':
        return 0;
    case '*':
        return 1;
    case '(':
        return -2;
    case ')':
        return -1;
    }
    return 0;
}
Node calc(const Node&a, const Node&b, char op){
    Node one;
    if(op == '+'){
        one.m = a.m + b.m;
        one.s = a.s + b.s;
        return one;
    } else if(op =='-'){
        one.m = a.m - b.m;
        one.s = a.s - b.s;
        return one;
    }
    // *
    if(a.m !=0){
        one.s = 0;
        one.m = a.m * b.s;
    } else if(b.m != 0){
        one.m = b.m * a.s;
        one.s = 0;
    } else {
        one.m = 0;
        one.s = a.s*b.s;
    }
    return one;
}
Node compute(int s, int e){
    vector<char> st;
    vector<Node> vt;
    Node tmp, a, b;
    for(; s<e; s++){
        if(buf[s] == '('){
            st.push_back(buf[s]);
        } else if(buf[s]=='x'){
            tmp.m = 1; tmp.s = 0;
            vt.push_back(tmp);
        } else if(isdigit(buf[s])){
            int t = 0;
            do{
                t *= 10;
                t += buf[s] -'0';
                s++;
            }while(isdigit(buf[s]));
            s--;
            a.m = 0; a.s = t;
            vt.push_back(a);
        } else {
            int t = getPrior(buf[s]);
            while(st.size() && getPrior(st.back()) >= t){
                b = vt.back(); vt.pop_back();
                a = vt.back(); vt.pop_back();
                a = calc(a, b, st.back());
                st.pop_back();
                vt.push_back(a);
            }
            if(buf[s]==')')
                st.pop_back();
            else
                st.push_back(buf[s]);
        }
    }
    while(st.size()){
        b = vt.back(); vt.pop_back();
        a = vt.back(); vt.pop_back();
        a = calc(a, b, st.back());
        st.pop_back();
        vt.push_back(a);
    }
    a = vt.back();
    return a;
}
void Expression(int s, int e, Node &val, int sign){
    val = compute(s, e);
    val.m *= sign;
    val.s *= sign;
}
void fun(){
    int i, j;
    res.m = res.s = 0;
    Node tmp;
    for(i=0; buf[i]!='='; i++)
        ;
    Expression(0, i, tmp, 1);
    res.m += tmp.m;
    res.s += tmp.s;

    j = i + 1;
    for(i=j; buf[i]!='\n'; i++)
        ;
    Expression(j, i, tmp, -1);
    res.m += tmp.m;
    res.s += tmp.s;

    if(res.m ==0){
        if(res.s ==0){
            printf("Infinitely many solutions.\n");
        } else {
            printf("No solution.\n");
        }
    } else {
        double t = -res.s;
        t /= res.m;
        printf("x = %.6lf\n", t);
    }
}

int main(){
    int tst = 0;

    while(fgets(buf, SIZ, stdin)!=NULL){
        printf("Equation #%d\n", ++tst);
        fun();
        printf("\n");
    }
    return 0;
}

