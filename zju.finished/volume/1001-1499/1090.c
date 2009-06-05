#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

const double PI = 3.141592653589793;
double a,b,c;

void fun(){
    double sum, bot;
    bot = (a + b + c)/2;
    
    bot = bot *(bot-a)*(bot -b) *(bot -c);
    bot = 2* sqrt(bot);
    
    sum = PI * a * b *c;
    sum /= bot;
    
    printf("%.2lf\n", sum);
    
}

int main(){
    double x1,y1,x2,y2,x3,y3;
    
    scanf("%lf %lf %lf %lf %lf %lf", &x1,&y1,&x2,&y2,&x3,&y3);
    while(!feof(stdin)){
		a = sqrt( (x1 -x2)*(x1-x2) + (y1-y2)*(y1-y2) );
		b = sqrt( (x1 -x3)*(x1-x3) + (y1-y3)*(y1-y3) );
		c = sqrt( (x3 -x2)*(x3-x2) + (y3-y2)*(y3-y2) );
		fun();
		
		scanf("%lf %lf %lf %lf %lf %lf", &x1,&y1,&x2,&y2,&x3,&y3);
	}
    
    return 0;
}
