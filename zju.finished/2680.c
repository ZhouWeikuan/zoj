#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 5,
};

typedef struct {
	int hour;
	int min;
	int angle;
}Time;

Time hand[Size];

int mycompare(const Time *a, const Time*b){
	if(a->angle != b->angle)
		return a->angle - b->angle;
	if(a->hour != b->hour)
		return a->hour - b->hour;
	return a->min - b->min;
}

void calc(Time *t){
	const static int hourdiv = 360/12;
	int h = t->hour;
	if( h >= 12)
		h -= 12;
	int sep = h * hourdiv;
	int m = t->min * 360/60;
	sep += (t->min) * hourdiv/60;
	if( m > sep)
		m-= sep;
	else
		m = sep - m;
	if(m > 180)
		m = 360 - m;
	t->angle = m;	
}

int main(){
	int tstcase;
	int i;
	scanf("%d ", &tstcase);
	while(tstcase --){
		for(i=0;i<Size;i++){
			scanf("%02d:%02d ", &hand[i].hour, &hand[i].min);
			calc(&hand[i]);
		}
		qsort(hand, Size, sizeof(Time), mycompare);
		printf("%02d:%02d\n", hand[2].hour, hand[2].min);
	}	

	return 0;
}
