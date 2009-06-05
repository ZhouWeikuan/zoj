/*
    只对一个组进行操作
    w[i][j]:  这个组的人数为I，同时总重量为J是否存在
*/
// copied from hengyang ba zhong

#include <stdio.h>
#include <string.h>

int w[100][30000];
int num[101];

int main()
{
    int n,max,tot,i,j,k;
    int tstcase = 0;
    while(scanf("%d",&n)!=EOF){
        tot=0;
        for(i=1;i<=n;i++){
             scanf("%d",num+i);
             tot+=num[i];
         }
        max=tot/2;    //max为两组的人数中小的那一组
        ++ tstcase;
        w[0][0]= tstcase;
        for(k=1;k<=n;k++){//依次对每个人进行处理
            for(i=(n+1)/2;i>=1;i--){ //这个组的人数不能超过(n+1)/2
                for(j=max;j>=num[k];j--){//组内总重量不超过全体总重量的一半
                    if(w[i][j] < tstcase && w[i-1][j-num[k]] == tstcase) 
                        w[i][j]= tstcase;
                }
            }
        }
        for(j=max;j>=0;j--)
            if(w[(n+1)/2][j] == tstcase || w[n/2][j] == tstcase)
                break;            
        printf("%d %d\n",j,tot-j);
    }
    return 0;
}  
