#include<iostream>
using namespace std;
// 一种可能的情况是：尾部有空格和tab，先将tab替换成空格，再统计空格数目
enum {
    SIZ = 400,
};
char buf[SIZ];
int tab,spc;
void fun(){
    tab = spc = 0;
    int i;
    while(fgets(buf,SIZ, stdin) && strcmp(buf,"##\n")!=0){
        for(i=0;buf[i]!='\n';i++){
            if(buf[i] =='\t'){
                tab++;
            }
        }
        i--;
        while(i>=0){
            if(buf[i]==' '){
                spc ++;
            } else if(buf[i] =='\t'){
                spc += 4;
            } else {
                break;
            }
            i--;
        }
    }
    printf("%d tab(s) replaced\n", tab);
    printf("%d trailing space(s) removed\n", spc);
}

int main(){
    int tstcase;
    
    scanf("%d",&tstcase);
    while(tstcase --){
        fun();
    }

    return 0;
}
