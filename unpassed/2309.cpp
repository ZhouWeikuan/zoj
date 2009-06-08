#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
#include <string>
// Wrong answer, what does substring here mean?
using namespace std;
enum {
    SIZ = 100008,
};
char buf[SIZ];
int K;
set<string> books;
string key;

void fun(){
    int valid = 0, full = 0;
    books.clear();
    key="";
    for(int i=0; i<26; i++){
        key += "0";
    }
    for(full=0; buf[full]>=32; ++full){
        if (!isalpha(buf[full])) continue;
        buf[valid] = tolower(buf[full]);
        ++key[buf[valid]-'a'];
        ++valid;
        if (valid >= K){
            if (books.find(key)!=books.end()){
                break;
            }
            books.insert(key);
            --key[buf[valid-K]-'a'];
        }
    }
    printf("%d\n", full);
}

int readIn(){
    scanf("%d ", &K);
    if (K == 0) return 0;
    fgets(buf, SIZ, stdin);

    return K;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

