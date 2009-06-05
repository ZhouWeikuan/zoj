#include<iostream>
#include<cstring>
using namespace std;
enum {
    SIZ = 32,
    ALP = 32,
};
char dat[SIZ];
char ges[SIZ];
char pre[SIZ];
int alp[ALP];
int ga[ALP];
bool getit;

int readIn(){
    memset(alp, 0, sizeof(alp));
    fgets(dat, SIZ, stdin);
    return strcmp(dat, "LINGO\n")!=0;
}
void prompt(){
    int i;
    for(i=0; dat[i]!='\n'; i++){
        alp[dat[i]-'A']++;
        pre[i] = (i==0?dat[i]:'.');
    }
    pre[i] = 0;
    printf("%s\n", pre);
}
bool invalid(){
    int i;
    for(i=0; ges[i]!='\n'; i++){
        if(!isupper(ges[i])) return true;
    }
    return (i!=5);
}
void output(){
    if(getit){
        printf("%s", ges);
        return;
    }
    int i;
    memset(ga, 0, sizeof(ga));
    for(i=0; ges[i]!='\n'; i++){
        if(ges[i] == dat[i]){
            ga[ges[i]-'A']++;
        }
    }
    for(i=0; ges[i]!='\n'; i++){
        if(ges[i] == dat[i]){
            pre[i] = dat[i];
        } else if(!isupper(ges[i]) || alp[ges[i]-'A'] <= ga[ges[i]-'A']){
            pre[i] = '.';
        } else {
            pre[i] = tolower(ges[i]);
            ga[ges[i]-'A']++;
        }
    }
    printf("%s\n", pre);
}
void strtolower(char *s){
    while(*s){
        *s = tolower(*s);
        s++;
    }
}
int main(){
    int cnt;
    fgets(dat, SIZ, stdin);
    while(readIn() > 0){
        printf("\n");
        prompt();
        getit = false;
        cnt = 0;
        for(fgets(ges, SIZ, stdin); ges[0]!='\n'; fgets(ges, SIZ, stdin)){
            cnt++;
            if(cnt >= 6 || getit) continue;
            if(invalid()){
                printf("%s\n", pre);
                continue;
            }
            if(strcmp(dat, ges) == 0) getit=true;
            output();
        }
        if(!getit){
            strtolower(dat);
            printf("%s", dat);
        }
    }
    return 0;
}

