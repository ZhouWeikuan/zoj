#include<iostream>
using namespace std;
enum {
    SIZ = 1008,
};
char neck[SIZ];
int num, len;
void fun(){
    num = strlen(neck);
    len = (num-1)/2;
    int flag = 0, j;
    for(int i=0;i<num;i++){
        flag = 1;
        // odd,注意odd与even的判断顺序
        for(j=1;j<=len;j++){
            if(neck[(i-j+num)%num] != neck[(i+j)%num]){
                flag = 0; break;
            }
        }
        if(flag){
            printf("Symmetric\n%d\n",(i+1));
            return;
        }

        flag = 1;
        // even
        for(j=0;j<=len;j++){// j<=len 不是j<len，这个让我错了很多次
            if(neck[(i+num-j)%num] != neck[(i+j+1)%num]){
                flag  = 0; break;
            }
        }
        if(flag){
            if(i==num-1){
                printf("Symmetric\n%d-%d\n", i+1,0);
            } else {
                printf("Symmetric\n%d-%d\n", i+1,i+2);
            }
            return;
        }
    }
    printf("Not symmetric\n");
}

int main(){
    
    while(scanf("%s", neck) > 0){
        fun();
    } 
    return 0;
}

