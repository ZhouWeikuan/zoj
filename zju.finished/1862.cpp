#include<iostream>


// 题目说明有点问题，有雷被触到
//      如果是x，输出周围雷的数目
//      如果是.，不输出
//      如果是雷，输出*，此规则覆盖以上规则
using namespace std;
enum {
    SIZ = 12,
};
int num;
char tab[SIZ][SIZ];
char mask[SIZ][SIZ];

void readIn(){
    int i;
    for(i=0;i<num;i++){
        scanf("%s", tab[i]);
    }
    for(i=0;i<num;i++){
        scanf("%s", mask[i]);
    }
}

int trans(){
    int i,j, t;
    int flag = 0;
    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            if(mask[i][j] == '.')
                continue;
            if(tab[i][j] == '*'){
                flag= 1; 
                continue;
            }
            t = 0;
            t += i>0 && tab[i-1][j] =='*';
            t += j>0 && tab[i][j-1] =='*';
            t += i<num-1 && tab[i+1][j] =='*';
            t += j<num-1 && tab[i][j+1] =='*';
            t += i>0&&j>0 && tab[i-1][j-1] =='*';
            t += i>0&&j<num-1 && tab[i-1][j+1] =='*';
            t += i<num-1&&j>0 && tab[i+1][j-1] =='*';
            t += i<num-1&&j<num-1&& tab[i+1][j+1] =='*';
            mask[i][j] = '0' + t;
        }
    }
    if(flag == 0)
        return 0;
    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            if(tab[i][j] == '*'){
                mask[i][j] = '*';
            }
        }
    }
    return 0;
}

void fun(){
    trans();
    for(int i=0;i<num;i++){
        printf("%s\n", mask[i]);
    }
}

int main(){
    int tstcase = 0;

    while(scanf("%d", &num) > 0){
        if(tstcase ++){
            printf("\n");
        }
        readIn();
        fun();
    }

	return 0;
}
