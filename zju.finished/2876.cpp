#include<iostream>
using namespace std;
enum {
    SIZ = 10008,
    LEN = 12,
};
int num;
char word[SIZ][LEN];
int ptr[SIZ];
struct Cmp{
    bool operator()(const int&a, const int&b)const{
        return strcmp(word[a], word[b])<0;
    }
}cmp;
bool match(char *a, char *b){
    while(*a&&*b&&*a==*b){
        ++a,++b;
    }
    return (*a==0||*b==0);
}

bool fun(){
    int i;
    for(i=1; i<num; i++){
        if(match(word[ptr[i-1]], word[ptr[i]])){
            return false;
        }
    }
    return true;
}

void readIn(){
    int i;
    scanf("%d",&num);
    for(i=0; i<num; i++){
        scanf("%s", word[i]);
        ptr[i] = i;
    }
    sort(ptr, ptr+num, cmp);
}
int main(){
    int tst, t;
    const char *ans[2] = {
        "NO", "YES"
    };
    scanf("%d", &tst);
    while(tst--){
        readIn();
        t = fun();
        printf("%s\n", ans[t]);
    }
    return 0;
}

