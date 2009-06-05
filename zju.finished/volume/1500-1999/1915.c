#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 1008,	
};

int num;
int grade[Size];
double average;

int main(){
	int tstnum;
	int i;
	int t;
	
	scanf("%d", &tstnum);
	while(tstnum --){
        scanf("%d", &num);
        average = 0;
        for(i=0;i<num;i++){
            scanf("%d", &grade[i]);
            average += grade[i];
        }
        average /= num;
        t = 0;
        for(i=0;i<num;i++){
            if(grade[i] > average)
                t++;
        }
        average = t *100;
        average /= num;        
        printf("%.3lf%%\n", average);
    }
	
	return 0;
}
