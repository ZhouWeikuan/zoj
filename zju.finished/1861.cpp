#include<iostream>
using namespace std;
enum {
    SIZ = 40,
};

char rep[10] = {0, 1, 5, 3, 4, 2, 9, 7, 8, 6};
char dig[SIZ];
int len;

int fun(){
    int i, t = dig[len], hi;
    if(rep[t] > t){
        dig[len] = rep[t];
        return 1;
    }
    hi = t;
    for(i=len-1; i>=0; i--){
        t = dig[i];
        if(t < hi || rep[t] > t){
            //adjust(i, hi);
            int k=i;
            for(int j=i+1;j<=len;j++){
                t = dig[j];
                if(t > dig[i] && t <= hi){
                    hi = t;
                    k = j;
                }
                if(rep[t] > dig[i] && rep[t] <= hi){
                    hi = rep[t];
                    dig[j] = rep[t];
                    k = j;
                }
            }
            t = dig[i];
            if(rep[t] > t && (hi < t || hi > rep[t])){
                dig[i] = rep[t];
            } else {
                swap(dig[i], dig[k]);
            }
            for(k= i+1; k<=len; k++){
                dig[k] = min(dig[k], rep[dig[k]]);
            }
            sort(dig+i+1, dig+len+1);
            return 1;
        }
        hi = max(hi, t);
    }
    return 0;
}

void trim(){
    len = 0;
    for(int i=0; dig[i]; i++){
        if(dig[i]!='.'){
            dig[len++] = dig[i] - '0';
        }
    }
    dig[len--] = 0;
}
void output(int s){
    if(s <=0){
        printf("The price cannot be raised.\n");
        return ;
    }
    for(s=0; s<len; s++){
        printf("%d", dig[s]);
    }
    printf(".%d\n", dig[len]);
}
int main(){

    scanf("%s", dig);
    while(dig[0]!='.'){
        trim();
        output(fun());
        scanf("%s", dig);
    }
    return 0;
}

