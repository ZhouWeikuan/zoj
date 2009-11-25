#include<iostream>
#include<algorithm>
#include<string>
#include<deque>
#include<cstdio>
#include<cstring>
using namespace std;
enum {
    SIZ = 104,
};
struct Node {
    deque<string> dq;
    void init(char *s){
        dq.clear();
        char *p = strtok(s, ",]");
        while(p){
            dq.push_back(p);
            p = strtok(NULL, ",]");
        }
    }
    void add(Node &o){
        while(!o.dq.empty()){
            dq.push_back(o.dq.front());
            o.dq.pop_front();
        }
    }

    void sub(Node &o){
        deque<string>::iterator it;
        while(!o.dq.empty()){
            it = find(dq.begin(), dq.end(), o.dq.front());
            if (it!=dq.end()){
                dq.erase(it);
            }
            o.dq.pop_front();
        }
    }

    void output(){
        printf("[");
        bool f = true;
        for (deque<string>::iterator it=dq.begin();
                    it != dq.end(); ++it){
            if (f){
                f = false;
            }else {
                printf(",");
            }
            printf("%s", (*it).c_str());
        }
        printf("]\n");
    }
};

char buf[SIZ];
Node a, b;

void fun(){
    char *p= index(buf, '+');
    if (p == NULL){
        p = index(buf, '-');
    }
    int op = *p;
    *(p-1) = 0;
    *p++ = 0;
    *p++ = 0;
    *p++ = 0;
    a.init(buf+1);
    b.init(p+1);
    if (op == '+'){
        a.add(b);
    } else {
        a.sub(b);
    }
    a.output();
}

int readIn(){
    cin.getline(buf, SIZ);
    if (buf[0] == '.') return 0;
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

