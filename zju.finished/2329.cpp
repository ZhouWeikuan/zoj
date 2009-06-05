#include<iostream>
using namespace std;
enum {
    SIZ = 1008,
    A = 0, 
    B = 1,
};
char str[SIZ];
int num, s;

void proc(){
    int i;
    num = strlen(str);
    s = 0;
    for(i=0;i<=num; i++){
        s += str[i]=='a';
    }
}

inline bool valid(int t){
    return t>=0 && t<num;
}

void fun(){
    int i;
    int t[2];
    for(i=0; i<num; i++){
        t[0] = i + num - s;
        t[1] = i + s;
        sort(t, t+2);
        if(t[0] == t[1]){
            t[1] = -1;
        }
        for(int j=0;j<2;j++){
            if(valid(t[j])){
                printf("%d,%d\n", i, t[j]);
            }
        }
    }
}

int main(){
    int tstcase = 0;

    while(scanf("%s ", str) > 0){
        printf("AB Circle #%d:\n", ++tstcase);
        proc();
        fun();
        printf("\n");
    }
    return 0;
}

