#include<stdio.h>
#include<math.h>
/*
 *      
 *  Euler定理，若k与m互素，则k^(x) = 1 mod m,
 *      其中　x 为m的缩系个数，即比m小且与m互素的个数 
 *       
        但是，如何得到最小的x，使得k^(x) = 1 mod m 
 *      
        本题用的是另一个性质        k%n = x,则
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
