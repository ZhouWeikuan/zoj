#include<iostream>
#include<cstring>
using namespace std;
enum {
    SIZ = 104,
    LEN = 24,
};
struct Node {
    char w[LEN];
    Node (){}
    Node(const Node &rhs){
        memcpy(w, rhs.w, sizeof(w));
    }
    bool operator < (const Node &rhs) const {
        return strcmp(w, rhs.w) < 0;
    }
};
Node words[SIZ];
char query[SIZ];
int num;
struct Term {  // val , 0-> norequire, 1 -> opt, 2 -> pos, 3 -> negative;
    char alp[26];
};

Term term[SIZ];
int tpos;


//一不小心，这里改了传来的参数，结果WA到死。
int match(char *w, const Term *p){
    bool opt = false, rule = true;
    int t;
    int cnt = 0;
    for( ; rule && *w; w++){
        t = *w - 'a';
        switch(p->alp[t]){
        case 0:
            break;
        case 1:
            opt = true;
            break;
        case 2:
            cnt |= 1<<t;
            break;
        case 3:
            rule = false;
            break;
        }
    }
    if(opt && rule){
        for(int i=0;i<26;i++){
            if(p->alp[i] == 2 && ((cnt>>i) &0x01) == 0){
                rule = false;
                break;
            }
        }
    }

    return (opt && rule)?1:0;
}

void parse(){
    int val;
    tpos = 0;
    char *p;
    p = strtok(query, "|");
    while(p){
        memset(&term[tpos], 0, sizeof(Term));
        val = 1;
        for(; *p; ++p){
            if(*p == '+'){
                val = 2;
            } else if(*p == '-'){
                val = 3;
            } else {
                term[tpos].alp[*p -'a'] = val;
            }
        }
        tpos ++;

        p = strtok(NULL, "|");
    }
}

int check(){
    parse();
    for(int i=0; i<num; i++){
        for(int j=0;j<tpos;j++){
            if(match(words[i].w, &term[j])){
                return i;
            }
        }
    }
    return -1;
}

void fun(){
    cin>>query;
    while(query[0] != '*'){
        int t = check();
        if(t < 0){
            cout<<"NONE"<<endl;
        } else {
            cout<<words[t].w<<endl;
        }
        cin>>query;
    }
    cout<<"$"<<endl;
}

int readIn(){
    num = 0;
    cin>>words[num].w;
    if(words[num].w[0] == '#')
        return 0;
    while(words[num].w[0] != '*'){
        ++num;
        cin>>words[num].w;
    }
    sort(words, words+num);
    return 1;
}
int main(){
    while(readIn() > 0){
        fun();
    }
    return 0;
}

