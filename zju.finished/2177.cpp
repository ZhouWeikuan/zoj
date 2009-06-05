#include<iostream>
#include<queue>
#include<vector>
/*
 *  使用KMP算法求出next数组，
 *  当next[i] = k 时，循环节长度为i + 1 - k, 循环次数为 (i + 1)/(i + 1 - k)
 *
 */ 
using namespace std;

enum {    
    TXT = 1000008,
};

int N;
char txt[TXT];
int  next[TXT];

void calc_next(){
    next[0]=0; // the initialization of the next[0]; 
    int temp; // the key iterator...... 

    for(int i=1;i<N;i++) 
    { 
        temp=next[i-1]; 

        while(txt[i]!=txt[temp]&&temp>0) 
        { 
            temp=next[temp-1]; 
        } 

        if(txt[i]==txt[temp]) 
            next[i]=temp+1; 
        else 
            next[i]=0; 
        
        int t = next[i];
        if(t < 0){
            continue;
        }
        int m = next[t];
        if(i - t == t - m && (i + 1) % (i -t +1 ) == 0){
            m = (i + 1) / ( i - t +1);
            printf("%d %d\n", i+1, m);
        }
    } 
}

void fun(){
    static int tstcase = 0;
    printf("Test case #%d\n", ++tstcase);
    calc_next();   
    
    printf("\n");
}

int main(){

    scanf("%d", &N);
    while( N ){
        scanf("%s", txt);
        fun();
        scanf("%d", &N);
    }

    return 0;
}

