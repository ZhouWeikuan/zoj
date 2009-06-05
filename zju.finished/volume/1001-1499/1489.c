#include<stdio.h>
#include<math.h>
/*
 *      
 *  Euler������k��m���أ���k^(x) = 1 mod m,
 *      ���С�x Ϊm����ϵ����������mС����m���صĸ��� 
 *       
        ���ǣ���εõ���С��x��ʹ��k^(x) = 1 mod m 
 *      
        �����õ�����һ������        k%n = x,��
                        (2*k) %n = (2*x)%n
 */     
int n;

void fun(){
    int i=1;
    int t = 2 %n;
    
    
    while(t != 1){
        t = t * 2;
        t = t%n;
        i ++;
    }
    printf("2^%d mod %d = 1\n",i,n);
}

int main(){        
    
    scanf("%d",&n);
    while(!feof(stdin)){
        if(n%2==0 || 2%n ==0){
            printf("2^? mod %d = 1\n",n);
        } else {
            fun();
        }
        
        scanf("%d",&n);
    }
    
    return 0;
}
