#include<iostream>
#include<set>
#include<map>
#include<cstring>
#include<cstdlib>
using namespace std;
/*
 * Oh SHIT! Does the hint in the bottom a real hint?!
 *   It leads me to think that only one bar can be recognised as dot!!!!
 *   Actally, it is one digit! Several bars on one digit can be read as dot!
 */
enum {
    SIZ = 104,
};
map<int, int> tab;
map<int, set<int> > mis;

char digStr[4][40] = {
    "._....._.._....._.._.._.._.._.",
    "|.|..|._|._||_||_.|_...||_||_|",
    "|_|..||_.._|..|._||_|..||_|._|"
};
char buf[20];

int parse(char s[][40], int p){
    int j;
    for (j=0; j<3; ++j){
        strncpy(&buf[j*3], &digStr[j][3*p], 3);
    }
    buf[9] = 0;
    int v = 0;
    for (j=0; j<9; ++j){
        v <<= 1;
        if (buf[j]!='.'){
            v |= 1;
        }
    }
    return v;
}

void mistake(int v, int i){
    for (int p=1,j=0; j<10; p<<=1, ++j){
        if (v & p){
            int nv = v & ~p;
            mis[nv].insert(i);
            mistake(nv, i);
        }
    }
}

void makeTable(){
    for (int i=0; i<10; ++i){
        int v = parse(digStr, i);
        tab[v] = i;
        mistake(v, i);
    }
}

int ansCnt;
char save[20];
char rest[20];
int val[20];

void dfs(int p, int d){
    if (d >= 9){
        rest[d] = 0;
        int v = 0;
        for (int i=0; i<9; ++i){
            v += (9-i)*(rest[i]-'0');
            v %= 11;
        }
        if (v == 0){
            ++ansCnt;
            if (ansCnt){
                strcpy(save, rest);
            }
        }
        return;
    }
    map<int, int>::iterator it = tab.find(val[d]);
    if (it != tab.end()){
        rest[d] = it->second + '0';
        dfs(p, d+1);
        if (ansCnt >= 2)
            return;
    }
    if (p == 0){
        map<int, set<int> >::iterator sit;
        sit = mis.find(val[d]);
        if (sit != mis.end()){
            set<int> &s = sit->second;
            for (set<int>::iterator si=s.begin(); si!=s.end(); ++si){
                rest[d] = *si + '0';
                dfs(1, d+1);
                if (ansCnt >= 2)
                    return;
            }
        }
    }
}

void fun(){
    ansCnt = 0;
    for (int i=0; i<9; ++i){
        val[i] = parse(digStr, i);
    }
    dfs(0, 0);
    if (ansCnt == 0){
        printf("failure\n");
    } else if (ansCnt >= 2){
        printf("ambiguous\n");
    } else {
        printf("%s\n", save);
    }
}

int readIn(){
    int i;
    for (i=0; i<3; ++i){
        if(scanf("%s", digStr[i]) < 0)
            return 0;
    }
    return 1;
}

int main(){
    makeTable();
    while(readIn() > 0){
        fun();
    }

    return 0;
}

