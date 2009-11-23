#include<iostream>
#include<string>
#include<cstdio>
#include<cctype>
#include<map>
#include<set>
using namespace std;
enum {
    SIZ = 5,
};

struct Node {
    map<string, int> cnt;
    map<int, set<string> > rev;
    void init(){
        cnt.clear();
        rev.clear();
    }
};

Node tree[10];

void fun(){
    for (int len=1; len<=5; ++len){
        printf("Analysis for Letter Sequences of Length %d\n", len);
        printf("-----------------------------------------\n");
        int cnt = 0;
        for (map<int, set<string> >::reverse_iterator it = tree[len].rev.rbegin();
                it!=tree[len].rev.rend() && cnt < 5; ++it){
            if (it->second.empty()){
                continue;
            }
            ++cnt;
            printf("Frequency = %d, Sequence(s) = (", it->first);
            bool f = true;
            for (set<string>::iterator sit = it->second.begin();
                    sit != it->second.end(); ++sit){
                if (f){
                    f = false;
                } else {
                    printf(",");
                }
                printf("%s", (*sit).c_str());
            }
            printf(")\n");
        }
        printf("\n");
    }
}

void parse(char *s, int pos){
    for (int i=1; i<=5; ++i){
        for (int j=0; j+i<=pos; ++j){
            string str(s+j, s+j+i);
            int t = tree[i].cnt[str];
            tree[i].rev[t].erase(str);
            tree[i].cnt[str] = ++t;
            tree[i].rev[t].insert(str);
        }
    }
}

void readIn(){
    char buf[120];
    int pos = 0;
    char ch;
    while(EOF!=(ch=fgetc(stdin))){
        if (isalpha(ch)){
            buf[pos++] = toupper(ch);
        } else if (pos > 0){
            buf[pos] = 0;
            parse(buf,pos);
            pos = 0;
        }
    }
}

int main(){

    readIn();
    fun();

    return 0;
}

