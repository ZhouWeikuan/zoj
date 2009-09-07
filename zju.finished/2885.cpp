#include<iostream>
using namespace std;
enum {
    SIZ = 10004,
};

char dir[SIZ*2];
int deep, cur;
int d[SIZ];
int c[SIZ];

void fun(){
    cur = 0, deep = 0;
    d[cur] = 0; c[cur] = 0;
    int pos = 0;
    while(dir[pos]){
        if (dir[pos]=='d'){
            ++cur;
            d[cur] = 0; c[cur] = 0;
            if (deep < cur)
                deep = cur;
        } else { // u;
            --cur;
            if (d[cur] < d[cur+1] + 1 + c[cur]){
                d[cur] = d[cur+1] + 1 + c[cur];
            }
            ++c[cur];
        }
        ++pos;
    }
    static int no = 1;
    printf("Tree %d: %d => %d\n", no++, deep, d[0] );
}

int readIn(){
    gets(dir);
    return dir[0]!='#';
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

