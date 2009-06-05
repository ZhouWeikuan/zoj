#include<iostream>
using namespace std;
enum {
    SIZ = 40,
};
int num;
int mat[SIZ];
char dat[SIZ];
char buf[SIZ];

int mutate(int pos){
    if(mat[pos]!=-1)
        return mat[pos];
    if(pos >= num){
        return 0;
    }
    if(isalpha(dat[pos])){
        int t = mutate(pos+1);
        t %= 10;
        dat[pos] = '0' + t;
        mat[pos] = t+ 1;
    }else if(dat[pos] != '0'){
        int t = dat[pos] - '0';
        dat[pos]--;
        if(pos + t >= num){
            mat[pos] = 1 + mutate(pos + 1);
        } else {
            mat[pos] = 1 + mutate(pos + t);
        }
    }else { // 0
        mat[pos] = 0;
    }
    return mat[pos];
}

void fun(){
    memset(mat, -1, sizeof(mat));
    mutate(0);
    printf("%s\n", dat);
}

int readIn(){
    scanf("%s", buf); // START ?
    if(strcmp(buf, "ENDOFINPUT") == 0)
        return 0;
    scanf("%d %s", &num, dat);
    return 1;
}
int main(){
    while(readIn() > 0){
        fun();
        scanf("%s", buf); // END
    }
    return 0;
}

