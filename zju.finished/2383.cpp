#include<iostream>
// accepted
using namespace std;
enum {
    SIZ = 10008,
};
int num;
int pos[SIZ];

bool fun(){
    int i, t;
    int lim = (num+1)/2;
    for(t=1; t<lim; t++){
        for(i=t*2; i<num; i++){
            if(pos[i-t] < pos[i]){
                if(pos[i-t-t]< pos[i-t])
                    return false;
            }else if(pos[i-t] > pos[i]){
                if(pos[i-t-t]> pos[i-t])
                    return false;
            }
        }
    }
    return true;
}
int readIn(){
    char ch;
    scanf("%d ", &num);
    if(num ==0) return 0;
    scanf("%c", &ch);
    int i, t;
    for(i=0; i<num; i++){
        scanf("%d", &t);
        pos[t] = i;
    }
    return num;
}
int main(){
    const char *ans[2] = {
        "no", "yes"
    };

    while( readIn() > 0){
        printf("%s\n", ans[fun()]);
    }
    return 0;
}
