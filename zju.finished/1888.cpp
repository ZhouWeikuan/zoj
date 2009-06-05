#include<iostream>
#include<string>
#include<ext/hash_map>
#include<set>

using namespace std;
using namespace __gnu_cxx; 
struct hasher {
    int operator()(const string &s) const {
        int t = 0;
        for(int i=0; s[i]; i++){
            t *= 10;
            t += s[i] -'a';
            t %= 17951;
        }
        return t;
    }
};
hash_map<string, int, hasher >  word;
set<string >  tab;
int num;
char str[1000];

char * parse(char *&s){
    char *p = NULL;
    while(*s && !isalpha(*s)){
        s++;
    }
    if(*s == 0)
        return NULL;
    p = s;
    while(*s && isalpha(*s)){
        *s = tolower(*s);
        s++;
    }
    if(*s){
        *s = 0;
        s++;
    }
    return p;
}

void fun(){
    char *p, *t;
    while( scanf("%s ", str) > 0 && strcmp(str, "EndOfText") != 0){
        p = t = str;
        while( (p = parse(t)) != 0 ){
            string s(p);
            int v = ++ word[s];
            if( v== num){
                tab.insert(s);
            }else if(v==num+1){
                tab.erase(s);
            }
        }
    }
    set<string >::iterator it;
    for(it = tab.begin(); it!=tab.end(); ++it){
        printf("%s\n", (*it).c_str());
    }
    if(tab.size() == 0){
        printf("There is no such word.\n");
    }
}

int main(){
    int tst = 0;

    while(scanf("%d ", &num) > 0){
        if(tst++){
            printf("\n");
        }
        word.clear();
        tab.clear();
        fun();
    }
    
	return 0;
}

