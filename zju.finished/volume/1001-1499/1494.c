#include<stdio.h>


int main(){
    int n,u,d;
    int x;
    int t;
    
    scanf("%d",&n);
    while(n){
		scanf("%d %d",&u,&d);
		if(n<=u){
			t = 1;
		} else {
			t = u -d;
			x = (n-u)/t;
			if(x * t < (n-u)){
				x ++;
			}
			t = x * 2+1;
		}
		printf("%d\n",t);
		scanf("%d",&n);
	}
    
    return 0;
}
