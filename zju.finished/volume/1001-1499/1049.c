#include<stdio.h>
#include<math.h>

double x,y;
const double PI = 3.1415927;

int fun(){
    int year;
    x = x*x + y *y;
    year = x * PI / 100.0;
    
    y = 100 * year /PI;
    if(y < x){
		year ++;
	} 
    return year;
}

int main(){
    int N;
    int i = 0;
    int t;
    
    scanf("%d",&N);
    while(N --){
		i++;
		scanf("%lf %lf", &x, &y);
		t = fun();
		printf("Property %d: This property will begin eroding in year %d.\n",i,t);
	
	}
    printf("END OF OUTPUT.\n");
    return 0;
}
