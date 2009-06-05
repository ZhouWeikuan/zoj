#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// 欺骗来的，原理还不清楚！！！
double width, length;
double big, little;

int fun(){
	if(width < 2*big+0.01)
		return 0;
	if(length < 2*big+0.01)
		return 0;
	width -= big+little;
	length -= big+little;
	width = width*width + length*length;
	length = big+little;
	length *= length;
	if(width < length+0.01)
		return 0;
	return 1;
}
const char *ans[2] = {
    "No",
    "Yes"
};
int main(){
	double t;
	
    scanf("%lf %lf %lf %lf", &width, &length, &big, &little);
	while(!feof(stdin)){
        if( width < length){
            t = width;
            width = length;
            length = t;
        }
        if( big < little){
            t = little; little = big; big = t;
        }
        printf("%s\n", ans[fun()]);
        scanf("%lf %lf %lf %lf", &width, &length, &big, &little);
    }
	return 0;
}
