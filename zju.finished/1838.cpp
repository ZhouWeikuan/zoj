#include<iostream>
#include<vector>
#include<string>
using namespace std;
enum {
    SIZ = 108,
    ALP = 26,
};
char word[SIZ] = {"the quick brown fox jumps over the lazy dog"};
int wl;
int num;
char line[SIZ][SIZ];
char alpha[ALP];
char offset[ALP];
char buf[SIZ];

bool match(char *l){
    int i,j,t,k;
    t = strlen(l);
    if(t!=wl) return false;
    memset(alpha, -1, sizeof(alpha));
    memset(offset, 0, sizeof(offset));
    for(i=0; i<wl; i++){
        if(l[i]==' ' || word[i] ==' '){
            if(l[i] != word[i]) return false;
        } else {
            t = word[i] - 'a';
            k = l[i] - 'a';
            if(alpha[k] == -1 || alpha[k] == t){
                alpha[k] = t;
                offset[t] = 1;
            } else {
                return false;
            }
        }
    }
    for(i=0; i<ALP; i++){
        if(offset[i]==0 || alpha[i]==-1) 
            return false;
    }
    return true;
}
void print(string &s){
    int i;
    for(i=0; s[i]; i++){
        buf[i] = alpha[s[i]-'a'] + 'a';
    }
    buf[i] = 0;
    printf("%s", buf);
}
void output(char *l){
    int i;
    for(i=0; l[i]; i++){
        if(l[i]!=' '){
            l[i] = alpha[l[i]-'a'] + 'a';
        }
    }
    printf("%s\n", l);
}
int fun(){
    int i;
    for(i=0; i<num; i++){
        if(match(line[i])){
            break;
        }
    }
    if(i==num) return -1;
    for(i=0; i<num; i++){
        output(line[i]);
    }
    return 1;
}

int readIn(){
    num = 0;
    while(gets(buf) && buf[0]!=0){
        strcpy(line[num++], buf);
    }
    return num;
}
int main(){
    int tst=0;
    wl = strlen(word);
    while(readIn() > 0){
        if(tst++) printf("\n");
        if( fun() < 0){
            printf("No solution.\n");
        }
    }
    return 0;
}

