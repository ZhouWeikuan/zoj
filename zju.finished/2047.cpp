#include<iostream>
#include<string>
#include<vector>
#include<cstring>
using namespace std;
enum {
    SIZ = 16,
};

char fstr[20][20];
void init(){
    fstr[0][0] = 0;
    for (int i=1; i<20; i++){
        strcpy(fstr[i], fstr[i-1]);
        fstr[i][i-1] = ' ';
        fstr[i][i] = 0;
    }
}

vector<string> vec;
char dat[SIZ];

bool valid(string &s){
    if(vec.size() == 0) return true;
    return s.length()>=vec.size() 
        && strncmp(s.c_str(), vec.back().c_str(), vec.size()) == 0;
}

void add(char *s){
    string str(s);
    while(!valid(str)){
        vec.pop_back();
    }
    printf("%s%s\n", fstr[vec.size()], s);
    vec.push_back(str);
}

void fun(){
    char *p;

    p = fgets(dat, SIZ, stdin);
    while( p && p[0] != '\n'){
        p = strtok(dat, "\t\n ");
        add(p);
        p = fgets(dat, SIZ, stdin);
    }
}

int readIn(){
}

int main(){
    init();
    int tst;

    //scanf("%d ", &tst);
    tst = 1;
    while(tst-- > 0){
        fun();
        if (tst)
            printf("\n");
    }

    return 0;
}

