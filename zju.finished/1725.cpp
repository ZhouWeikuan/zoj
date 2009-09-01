#include<iostream>
#include<string>
#include<vector>
using namespace std;
enum {
    SIZ = 104,
};
struct Node {
    int type; // 0, integers 1, operators 2, string
    int val;
    string name;
};
vector<Node> vec;

int check(int v){
    if (v=='*'||v=='/')
        return 2;
    if (v!='=')
        return 1;
    return 0;
}

int find(){
    int p = 0;
    int r = 0;
    for (int i=1; vec[i].val !='='; i+=2){
        int t = check(vec[i].val);
        if (p < t){
            r = i;
            p = t;
        }
    }
    return r;
}

void solve(int p){
    if (vec[p].val== '*'){
        vec[p-1].val *= vec[p+1].val;
    } else if (vec[p].val == '/'){
        vec[p-1].val /= vec[p+1].val;
    } else if (vec[p].val == '+'){
        vec[p-1].val += vec[p+1].val;
    } else if (vec[p].val == '-'){
        vec[p-1].val -= vec[p+1].val;
    }
    vec.erase(vec.begin()+p, vec.begin()+p+2);
}

void output(){
    printf("%d", vec[0].val);
    for (int i=1; i<vec.size(); ++i){
        if (vec[i].type == 0){
            printf(" %d", vec[i].val);
        } else if (vec[i].type == 1){
            printf(" %c", vec[i].val);
        } else {
            printf(" %s", vec[i].name.c_str());
        }
    }
    printf("\n");
}

void fun(){
    int p;
    output();
    while(p = find()){
        solve(p);
        output();
    }
}

int readIn(){
    int v;
    char ch;
    vec.clear();
    Node o;
    if (scanf("%d", &v) < 0)
        return 0;
    o.type = 0; o.val = v;
    vec.push_back(o);
    scanf(" %c", &ch);
    while(ch != '='){
        o.type = 1; o.val = ch;
        vec.push_back(o);
        scanf("%d", &v);
        o.type = 0; o.val = v;
        vec.push_back(o);
        scanf(" %c", &ch);
    }
    o.type = 1; o.val = ch;
    vec.push_back(o);
    char buf[10];
    scanf(" %s", buf);
    o.type = 2; o.name = buf;
    vec.push_back(o);
    return 1;
}

int main(){
    int t = 0;
    while(readIn() > 0){
        if (t++) printf("\n");
        fun();
    }

    return 0;
}

