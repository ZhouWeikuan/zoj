#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const char * ans[4] = {
	"Wide Receiver",
	"Lineman",
	"Quarterback",
	"No positions"
};

typedef struct {
	double speed;
	double weight;
	double strength;	
}Node;

Node person;
Node ball[3] = {
	{4.5,150,200},
	{6.0,300,500},
	{5.0,200,300}
};

void fun(){
    int i,t= 0;
    for(i=0;i<3;i++){
		if(person.speed <= ball[i].speed && person.weight>= ball[i].weight 
		&&person.strength>= ball[i].strength){
			if(t==0){
				t = 1;
				printf("%s",ans[i]);
			} else {
				printf(" %s",ans[i]);
			}
		}
	}
	if(t==0){
		printf("%s",ans[i]);
	}
	printf("\n");
}

int main(){
    
    scanf("%lf %lf %lf", &person.speed, &person.weight, &person.strength);
    while(person.speed> 0 || person.strength >0 || person.weight >0){
		fun();
		scanf("%lf %lf %lf", &person.speed, &person.weight, &person.strength);
	}
    
    return 0;
}
