#include<iostream>

using namespace std;
enum {
    SIZ = 36,
};
char str[SIZ];
int  val[SIZ];
int  base, len;

inline int c2d(char c){
    return c-'0';
}

// compare [s,e] with [base, len], return >= 0 if greater or equal.
int cmp(int s, int e){
    int len1 = e - s + 1, len2= len - base + 1;
    if(len1 != len2){
        return len1 - len2;
    }
    int t=base;
    for(;s<=e;s++, t++){
        if(str[s] != str[t]){
            return str[s] - str[t];
        }
    }
    return 0;
}

int dp(int e){
    if(e < 0)   return 1; // a valid presentation
    if(val[e] != -1)   return val[e]; // counted before.
    
    int t = 0;    
    val[e] = 0;
    for(t=e; t>=0; t--){        
        if(cmp(t,e) >= 0){ // not greater than base.
            break;
        }
        if(str[t] != '0' || (t==e && t!=0)){ // no leading zero, or it is zero and not the first element.
            val[e] += dp(t-1);
        }
    }
    return val[e];
}

// check for base's validity.
bool validBase(){
    int t = 0;
    for(int i=base; i<= len; i++){
        t *= 10;
        t += str[i]-'0';
        if(t >= 2){
            return true;
        }
    }
    return false;
}

int fun(){
    int ret = 0;    
    len = strlen(str)-1;
    
    for(base = len; base>0; base--){
         if(str[base] != '0' && validBase()){
             if(base==1 && str[0] =='0'){ // check for [0,base]
                 ret ++;
             } else {
                 memset(val, -1, sizeof(val));
                 ret += dp(base-1); // dynamic programming for the valid representation.
             }            
        }
    }
    return ret;
}

int main(){
    int t;
    while(scanf("%s", str) && str[0] != '#'){
        t = fun();
        if(t > 0){
            printf("The code %s can represent %d numbers.\n", str, t);
        } else {
            printf("The code %s is invalid.\n", str);
        }
    }
    return 0;
}