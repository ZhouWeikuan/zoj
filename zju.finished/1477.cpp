#include<iostream>
using namespace std;
// 一开始以为数据是小写字母串，SIGSEGV了
enum {
    SIZ = 108,
    ALP = 256,
};
int     num;
int     next[ALP];  // same char list
int     ptr[SIZ];   // point to the next same char from current char
char    str[SIZ];   // buffer
char    out[SIZ];

void encode(){
    int v, i, t;    
    for(i=num-1; i>=0; i--){
        v = str[i];
        ptr[i] = next[v];
        next[v] = i;
    }    
    for(i=0, t=0; i<ALP; i++){
        for(v=next[i]; v>=0; v = ptr[v]){
            out[t++] = v==0?str[num-1]:str[v-1];            
        }
    }
    out[t] = 0;
    printf("%s\n", out);
}
void decode(){
    int v, i, t;
    out[0] = str[--num];
    out[num] = str[num] = 0;
    for(i=0; i<num; i++){
        v = str[i];
        ptr[i] = next[v];
        next[v] = i;
    }
    static int tail[ALP];
    static int head[ALP];
    t = 0;
    for(i=0; i<ALP; i++){
        head[i] = t;
        for(v=next[i]; v>=0; v=ptr[v]){
            t++;
        }
        tail[i] = t-1;
    }    
    for(i=num-1; i>0; i--){
        t = i==num-1?0:i+1;
        t = out[t];
        if(i == num-1){
            out[i] = str[head[t]++];
        } else {
            out[i] = str[tail[t]--];
        }
    }
    printf("%s\n", out);
}
void fun(){
    char c = str[0];
    scanf("%s", str);
    num = (int)strlen(str);
    memset(next, -1, sizeof(next));    
    if(c == 'e'){  // encode        
        encode();
    } else {            // decode        
        decode();
    }
}

int main(){
    
    while( scanf("%s", str) > 0){
        fun();
    }       
    return 0;
}
