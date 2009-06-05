#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<set>
/* Wrong Answer */
using namespace std;
enum {
    SIZ = 1004,
    LEN = 16,
};
int num;
char dat[SIZ][LEN];
char ans[LEN];
char buf[LEN*2];
char trimmed[LEN*2];
int pos;
set<string> tab;

bool match(char *d, char *s){
    if(*d==0){
        return (*s==0||*s=='*');
    }
    if(*s==0){
        return false;
    }else if(*s=='*'){
        return true;
    }else if(*s=='?' || *s==*d){
        return match(d+1, s+1);
    }
    return false;
}
bool matchFile(char *dst, char *src){
    bool ret = false;
    char *d = strchr(dst, '.');    
    char *s = strchr(src, '.');
    *s = *d = 0;
    if(match(d+1, s+1) && match(dst, src))
        ret = true;
    *s = *d = '.';
    return ret;
}
void fun(){
    int i;
    for(set<string>::iterator s=tab.begin();
            s!=tab.end(); ++s){
        for(i=0; i<num; i++){
            if(dat[i][0]=='+' && matchFile(&dat[i][1], (char*)s->c_str())){
                break;
            }else if(dat[i][0]=='-' && !matchFile(&dat[i][1], (char*)s->c_str())){
                break;
            }
        }
        if(i==num){
            strcpy(ans, s->c_str());
            return;
        }
    }
    strcpy(ans,"");
    return;
}

void trim(char *s){
    int p=-1;
    while(*s){
        if(*s=='?'){
            trimmed[++p] = *s;
        }else if(*s=='*'){
            if(p>=0 && (trimmed[p]=='?'||trimmed[p]=='*'))
                trimmed[p] = *s;
            else
                trimmed[++p] = *s;
        }else {
            trimmed[++p]= *s;
        }
        s++;
    }
    trimmed[++p] = 0;
}
void make_res(const char *suf){
    strcpy(&buf[pos], suf);
    trim(buf);
    string s(trimmed);
    tab.insert(s);
}
void gen(const char *s){
    if(*s==0){
        make_res("");
    }else if(*s=='.'){
        buf[pos++] = '.';
        gen(s+1);
        --pos;
    } else {
        //same
        buf[pos++] = *s;
        gen(s+1);
        --pos;
        //?
        buf[pos++] = '?';
        gen(s+1);
        --pos;
        //*
        buf[pos++] = '*';
        char *p = strchr(s, '.');
        if(p!=NULL){
            gen(p);
        } else {
            gen("");
        }
        --pos;
    }
}

void myget(char *s, int sz, FILE *fp){
    fgets(s, sz, fp);
    int l = strlen(s) - 1;
    if(s[l]=='\n' || s[l]=='\r'){
        s[l] = 0;
    }
}
int readIn(){
    int sub=0, len=1000;
    num = 0;

    myget(dat[num], LEN, stdin);
    while(dat[num][0]!=0){
        char *p = strchr(dat[num], '.');
        if(p == NULL)
            strcat(dat[num], ".");
        if(dat[num][0]=='-'){
            sub++;
            int l = strlen(dat[num]);
            if(l < len){
                len = l;
                strcpy(ans, dat[num]);
            }
        }

        num++;
        myget(dat[num], LEN, stdin);
    }
    if(sub == 0){
        strcpy(ans, ".");
        return 0;
    } else if(sub == num){
        strcpy(ans, "*.*");
        return 0;
    }

    pos = 0;
    gen(&ans[1]);
    return 1;
}

int main(){
    int tst;

    scanf("%d ", &tst);
    while(tst--){
        tab.clear();
        if(readIn()){
            fun();
        }
        if(ans[0] == 0)
            printf("IMPOSSIBLE\n");
        else
            printf("DEL %s\n", ans);
        if(tst)
            printf("\n");
    }
    return 0;
}

