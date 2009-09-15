#include<iostream>
#include<string>
#include<map>
using namespace std;
enum {
    SIZ = 10004,
};

int N, M;
int cnt[SIZ];
int seq[SIZ];
char dat[60];

void fun(){
    bool flag = true;
    for (int i=0; i<N; ++i){
        ++cnt[seq[i]];
        if (cnt[seq[i]]!=i/M){
            flag = false;
            break;
        }
    }

    const char *ans[2] = {
        "Random", "Either"
    };
    printf("%s\n", ans[flag]);
}

int readIn(){
    if (scanf("%d", &N)<0) return 0;
    gets(dat);
    map<string, int> tab;
    map<string, int>::iterator it;
    M = 0;
    for (int i=0; i<N; ++i){
        cnt[i] = -1;
        gets(dat);
        string s(dat);
        it = tab.find(s);
        if (it==tab.end()){
            seq[i] = M;
            tab[s] = M;
            ++M;
        } else {
            seq[i] = it->second;
        }
    }
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

