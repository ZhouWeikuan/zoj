#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<set>
using namespace std;
enum {
    SIZ = 104,
};

struct cmp{
    bool operator()(const string&a, const string&b){
        return strcasecmp(a.c_str(), b.c_str()) < 0;
    }
};

char buf[SIZ];
map<string, map<string, set<int>, cmp>, cmp> tab;
const char *strBlank = " \t\n\r";

char *trim(char *s){
    int len = strlen(s);
    while(len && isblank(s[len-1])){
        s[--len] = 0;
    }
    while(isblank(*s))
        ++s;
    return s;
}

void work(char *s, int pageNo){
    char *p = index(s,'%');
    if (p)
        s = p + 1;
    p = index(s, '$');
    if (p){
        *p++ = 0;
    }
    s = trim(s);
    if (p){
        p = trim(p);
    }else{
        p = "";
    }
    string a(s);
    string b(p);
    tab[a][b].insert(pageNo);
}

void parse(const char *str){
    tab.clear();
    int pageNo = 1;
    while(*str){
        if (*str=='&'){
            ++pageNo;
        }
        if(*str=='{'){
            ++str;
            int i=0;
            while(*str!='}'){
                buf[i++] = *str;
                ++str;
            }
            buf[i] = 0;
            work(buf, pageNo);
        }
        ++str;
    }
}

bool fun(){
    string s;
    gets(buf);
    if (strcmp(buf,"**")==0) 
        return false;
    while(strcmp(buf,"*")!=0){
        s += buf;
        gets(buf);
    }
    parse(s.c_str());
    return true;
}

void outSet(set<int> &s){
    for(set<int>::iterator it=s.begin(); it!=s.end(); ++it){
        printf(", %d", *it);
    }
}

void outstr(const string&s, map<string, set<int>, cmp> &item){
    map<string, set<int>, cmp>::iterator it;
    printf ("%s", s.c_str());
    bool f = true;
    for (it=item.begin(); it!=item.end(); ++it){
        if (it->first==""){
            outSet(it->second);
            continue;
        }
        printf("\n+ %s", it->first.c_str());
        outSet(it->second);
        f = false;
    }
    printf("\n");
}

void output(){
    map<string, map<string, set<int>, cmp>, cmp>::iterator it;
    for (it=tab.begin(); it!=tab.end(); ++it){
        outstr(it->first, it->second);
    }
}

int main(){
    int doc = 0;
    for(;fun();){
        printf("DOCUMENT %d\n", ++doc);
        output();
    }

    return 0;
}

