#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
// >=0, win
// ==-1, draw
// else, lose
enum {
    SIZ = 18,
};

unsigned key;
char buf[SIZ];
map<unsigned,  int> tab; // (t>>8)&0xff, t&0xff
map<unsigned,  int>::iterator it;

int search(unsigned k){
    it = tab.find(k);
    if (it!=tab.end()) return it->second;


    tab.insert(make_pair(k, ans));
    return ans;
}

void fun(){
    int t = search(key);
    if (t >= 0){
        int c = t &0xff;
        t>>=8;
        printf("(%d,%d)\n", t, c);
    } else {
        printf("#####\n");
    }
}

int readIn(){
    scanf("%s ", buf);
    if (buf[0] == '$') return 0;
    key = 0;
    for (int i=0; i<4; ++i){
        scanf("%s ", buf);
        for (int j=0; j<4; ++j){
            key *= 3;
            if (buf[j] == '.') {
                key += 0;
            } else if (buf[j] == 'o'){
                key += 1;
            } else {
                key += 2;
            }
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

