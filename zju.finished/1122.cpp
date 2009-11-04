#include<cstdio>
#include<iostream>

using namespace std;
struct Time {
	int hour;
	int min;
};
Time begin,end;

//set 720 degree as a circle
//each between clock has  an 60 degree
void parse(Time &t){
	t.hour %= 12;
	t.hour *= 60;
	t.hour += t.min;
	t.min *= 12;
}
int simulate(){
	int ret =0;
	if(begin.hour == begin.min)
		ret ++;
	while(begin.hour != end.hour || begin.min != end.min){
		if(begin.min < begin.hour && begin.min+12 > begin.hour){
			ret++;
		}
		begin.min += 12;
		begin.hour += 1;
		if(begin.min >= 720){
			begin.min = 0;
		}
		if(begin.hour >=720)
			begin.hour = 0;
		
	}
	return ret;
}

int main(){
	int t = 0; 
	printf("Program 3 by team X\n");
	printf("Initial time  Final time  Passes\n");
	while(cin>>begin.hour>>begin.min>>end.hour>>end.min){
		printf("       %02d:%02d       %02d:%02d      ",
			begin.hour,begin.min,end.hour,end.min);
		parse(begin);
		parse(end);
		t = simulate();
		printf("%2d\n",t);
	}
	printf("End of program 3 by team X\n");

	return 0;
}
