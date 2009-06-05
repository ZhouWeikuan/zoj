#include<iostream>
#include<cstring>
#include<string>
#include<map>
using namespace std;
enum {
    SIZ = 10000,
};
char buf[SIZ];
map<string, int> tab;
map<string, int>::iterator it;

void init(){
    tab["zero"] = 0; tab["one"] = 1; tab["two"] = 2;
    tab["three"] = 3; tab["four"] = 4; tab["five"] = 5;
    tab["six"] = 6, tab["seven"] = 7, tab["eight"]=8;
    tab["nine"] = 9, tab["ten"] = 10, tab["eleven"] = 11;
    tab["twelve"] = 12, tab["thirteen"] = 13, tab["fourteen"] = 14;
    tab["fifteen"] = 15, tab["sixteen"] = 16, tab["seventeen"] = 17;
    tab["eighteen"] = 18, tab["nineteen"] = 19, tab["twenty"] = 20;
    tab["thirty"] = 30, tab["forty"] = 40, tab["fifty"] = 50;
    tab["sixty"] = 60, tab["seventy"] = 70, tab["eighty"] = 80;
    tab["ninety"] = 90;
}

int fun(){
    int m[3] = {0};
    int v = 0;
    char *p = buf;
    const char *del = " \n\t\r";
    p = strtok(p, del);
    while(p != NULL){
        if ( p == string("million")){
            m[2] = v; v = 0;
        } else if (p == string("thousand")){
            m[1] = v; v = 0;
        } else if (p == string("hundred")){
            v *= 100;
        } else {
            it = tab.find(p);
            if (it != tab.end()){
                v += it->second;
            }
        }

        p = strtok(NULL, del);
    }
    m[0] = v;
    v = (m[2] * 1000 + m[1]) * 1000 + m[0];
    return v;
}

int main(){
    init();
    int tst;
    scanf("%d ", &tst);
    while(tst --){
        fgets(buf, SIZ, stdin);
        printf("%d\n", fun());
    }

    return 0;
}

