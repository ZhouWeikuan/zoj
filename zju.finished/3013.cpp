#include<iostream>
#include<set>
using namespace std;
enum {
   LEN = 8,
};

typedef unsigned long long ullong;
set<ullong> tab;
int len;
char dat[4100];
int  ptr[4100];
int  sum[4100];
int M, N;

void segment(){
    int i, j;
    ullong v;
    ptr[len] = -1; sum[len] = 0;
    for (i=len-1; i>=0; --i){
        ptr[i] = i+1;
        sum[i] = 1 + sum[i+1];
        v = 0;
        for (j=1; j<=LEN && dat[i+j-1]; ++j){
            v *= 27;
            v += dat[i+j-1] - 'a' + 1;
            if (tab.find(v) != tab.end()){
                if (sum[i] > sum[i+j]){
                    sum[i] = sum[i+j];
                    ptr[i] = i+j;
                }
            }
        }
    }
    printf("%d\n", sum[0]);
    j = ptr[0];
    // bool lw = sum[0] == sum[j];
    for (i=0; i<len; ++i){
        if (i == j){
            j = ptr[i];
            //if (sum[i] == sum[j] || lw)
                putchar('#');
            //lw = sum[i] == sum[j];
        }
        putchar(dat[i]);
    }
    printf("\n");
}

void insert(){
    ullong v = 0;
    for (int i=0; dat[i]; ++i){
        v *= 27;
        v += dat[i] - 'a' + 1;
    }
    tab.insert(v);
}

int readIn(){
    if (scanf("%d%d", &M, &N) < 0)
        return 0;
    tab.clear();
    while(M--){
        scanf("%s", dat);
        insert();
    }
    return 1;
}

void fun(){
    while(N--){
        scanf("%s", dat);
        len = strlen(dat);
        segment();
    }
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

