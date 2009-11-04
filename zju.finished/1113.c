#include <stdio.h>
/********************************
	本程序能正常通过 
*********************************/
long jie(int n){
int i;
long sum=1;
if(n==0||n==1)return 1;
for(i=n;i>1;i--) sum*=i;
return sum;
}
main()
{
int n,i;
double e;
printf("n e\n");
printf("- -----------\n");
for(n=0;n<10;n++){
e=0;
for(i=0;i<=n;i++)
e+=1.0/jie(i);
if(n<3) printf("%d %g\n",n,e);
else printf("%d %1.9f\n",n,e);
}
}
