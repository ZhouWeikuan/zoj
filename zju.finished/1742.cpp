#include<iostream>
#include<cstdio>
#include<string>
#include<map>
#include<queue>
using namespace std;

const char empty = 10;
string dst;
string src;
int rev[100];
map<string, int> cost;

void fun(){
    if (src == dst){
        printf("0\n");
        return ;
    }
    queue<string> q;
    q.push(src);
    int i, e, step;
    while(!q.empty()){
        string &s = q.front();
        step = cost[s] + 1;
        e = 0;
        for (i=0; s[i]; ++i){
            if (s[i] > empty){
                rev[s[i]] = i;
            } else {
                rev[e++] = i;
            }
        }
        for (i=0; i<e; ++i){
            int p = rev[i] - 1;
            if (s[p] % 10 >= 7)
                continue;
            int t = s[p] + 1;
            string str(s);
            swap(str[rev[i]], str[rev[t]]);
            if (str == dst){
                printf("%d\n", step);
                return ;
            } else if (cost.find(str) == cost.end()){
                q.push(str);
                cost.insert(make_pair(str, step));
            }
        }

        q.pop();
    }
    printf("%d\n", -1);
}

void format(){
    for (int i=0; src[i]; ++i){
        if (src[i] % 10 == 1){
            if (i % 8){
                int t = src[i] / 10;
                t = (t - 1) * 8;
                swap(src[t], src[i]);
            }
        }
    }
    cost[src] = 0;
}

void readIn(){
    int t;
    src.clear();
    for (int i=0; i<4; ++i){
        src += empty;
        for (int j=0; j<7; ++j){
            scanf("%d", &t);         
            src += t;
        }
    }
    cost.clear();
    format();
}

void init(){
    dst = "";
    for (int i=1; i<=4; ++i){
        for (int j=1; j<=7; ++j){
            dst += (i*10) + j;
        }
        dst += empty;
    }
}

int main(){
    init();
    int gn;
    scanf("%d", &gn);
    while(gn-- > 0){
        readIn();
        fun();
    }

    return 0;
}

