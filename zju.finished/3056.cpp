#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
enum {
    SIZ = 104,
};

char buf[SIZ];
char tmp[SIZ];
map<string, string> tab;

void trans(char *s, char *e){
    string a(s, e);
    if (a.length() > 2){
        strcpy(tmp, a.c_str());
        sort(tmp+1, tmp+a.length()-1);
        a = tmp;
    }
    map<string, string>::iterator it= tab.find(a);
    strncpy(s, it->second.c_str(), it->second.length());
}

void fun(){
    char *p = fgets(buf, SIZ, stdin);
    char *e;
    while(p != NULL){
        while(*p != '\n'){
            if (!islower(*p)){
                ++p;
                continue;
            }
            e = p + 1;
            while(islower(*e)){
                ++e;
            }
            trans(p, e);
            p = e;
        }
        printf("%s", buf);
        p = fgets(buf, SIZ, stdin);
    }
}

void readIn(){
    string a, b;
    scanf("%s ", buf);
    b = buf;
    while(b!="DICTIONARY_DEFINE_OVER"){
        if (b.length() > 2){
            sort(buf+1, buf+b.length()-1);
            a = buf;
        } else {
            a = b;
        }
        tab[a] = b;
        scanf("%s ", buf);
        b = buf;
    }
}

int main(){

    readIn();
    fun();

    return 0;
}

