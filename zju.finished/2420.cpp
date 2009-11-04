#include<iostream>

using namespace std;

int syear=2000;
int smonth = 0;
int sday = 0;

char *weekname[7] = {
	"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday","Saturday"
};

int monthday[2][12] = {
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};

int leapyear(int y){
	if(y%4!=0)
		return 0;
	if(y%100 !=0)
		return 1;
	if(y%400 == 0)
		return 1;
	return 0;
}

int fun(int diff){
    int y = syear, m = smonth, d = sday;
    int yearday;
    int (*mptr);
    int weekday = 6;
    weekday += diff;
    weekday %= 7;
    
    do {
    	if(leapyear(y)){
			yearday = 366;
			mptr = monthday[1];
		} else {
			yearday = 365;
			mptr = monthday[0];
		}
		if(diff >= yearday){
			diff -= yearday;
			y++;
		}	else {
			break;
		}
	} while( diff);
    
    while(diff >= mptr[m]){
		diff -= mptr[m];
		m++;
	}
    d += diff;
    d++;
    m ++;
    printf("%4d-%02d-%02d %s\n",y,m,d,weekname[weekday]);
}

int main(){
    int diff;
    
    cin>>diff;
    while(diff > 0){
		fun(diff);
		
		cin>>diff;
	}
    
    return 0;
}
