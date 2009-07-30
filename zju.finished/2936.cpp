#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
enum {
    SIZ = 26,
};

int tab[SIZ][SIZ];

namespace Perm {
    bool hasOut(int v[SIZ]){
        for (int i=0; i<SIZ; ++i)
            if (v[i] > 0)
                return true;
        return false;
    }
    void output(int v[SIZ]){
        for (int i=0; i<SIZ; ++i){
            if (v[i] > 0){
                printf("%c", i+'a');
            }
        }
    }
    bool equal(int a[SIZ], int b[SIZ]){
        for (int i=0; i<SIZ; ++i){
            if ((a[i] > 0 || b[i] > 0) && a[i]!=b[i] ){
                return false;
            }
        }
        return true;
    }
    void set(int v[SIZ], char *s){
        for (int i=0; i<SIZ; ++i)
            v[i] = 0;
        for (; *s; ++s){
            v[*s-'a'] = 1;
        }
    }
    void sub(int v[SIZ], char *s){
        for (; *s; ++s){
            v[*s-'a'] = -1;
        }
    }
    void add(int v[SIZ], char *s){
        for (; *s; ++s){
            v[*s-'a'] = 1;
        }
    }
};
char buf[100];

void process(char *s){
    char *p; 
    void (*fun)(int *, char *) = 0;
    if (p = strchr(s, '=')){
        fun = Perm::set;
    } else if (p = strchr(s, '+')){
        fun = Perm::add;
    } else if( p = strchr(s, '-')){
        fun = Perm::sub;
    } else {
    }

    for (char *t=s; t<p; ++t){
        fun(tab[*t-'A'], p+1);
    }
}

void output(){
    int pos = 0;
    int *pre = 0;
    for (int i=0; i<SIZ; ++i){
        if (!Perm::hasOut(tab[i]))
            continue;
        if (pre == 0){
            buf[pos++] = 'A' + i;
            pre = tab[i];
        } else if(Perm::equal(tab[i], pre)){
            buf[pos++] = 'A' + i;
        } else {
            buf[pos] = 0;
            printf("%s", buf);
            Perm::output(pre);
            pos = 0;
            pre = tab[i];
            buf[pos++] = 'A' + i;
        }
    }
    if (pre){
        buf[pos] = 0;
        printf("%s", buf);
        Perm::output(pre);
    }
    printf("\n");
}

void fun(){
    char *del = ",\n\t";
    char *p = strtok(buf, del);
    memset(tab, 0, sizeof(tab));
    while(p){
        process(p);
        p = strtok(NULL, del);
    }
    output();
}

int main(){
    int tst = 0;
    fgets(buf, 100, stdin);
    while(buf[0] != '#'){
        printf("%d:", ++tst);
        fun();
        fgets(buf, 100, stdin);
    }

    return 0;
}

