#include<iostream>

using namespace std;
int year, month, day;

int montable[13] = {
	31,28,31,30,31,30,31,31,30,31,30,31
};
const char *monthname[] = {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};
const char *weekname[] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday",
};


int leapyear(int y){
	if(y%4 !=0)
		return 0;
	if(y < 1752)
		return 1;
	if(y%100 !=0)
		return 1;
	if(y%400==0){
		return 1;
	}
	return 0;
}

int getpassday(int y, int m, int d){
	int k = 0;
	int ret = 0;
	while(k < m){
		ret += montable[k];
		k ++;
	}
	ret += d;
	ret += (m>=2 && leapyear(y));
	return ret;
}

int calc_low(){
	int w = getpassday(1752,8,2) - getpassday(year,month,day);
	int y = year;
	while(y < 1752){
		w += 365 + leapyear(y);
		y ++;
	}
	w = -w;
	w += 3;
	w %= 7;
	w += 7;
	w %= 7;
	return w;
}
int calc_high(){
	int w = getpassday(year,month,day) - getpassday(1752,8,14);
	int y = 1752;
	while(y < year){
		w += 365 + leapyear(y);
		y ++;
	}
	w += 4;
	w %= 7;
	return w;
}

int calc(){
	if(day > montable[month] + (month==1 && leapyear(year)) ){
		return -1;
	}
	if(year < 1752){
		return calc_low();
	}else if(year > 1752){
		return calc_high();
	}
	if(month < 8 ){
		return calc_low();
	}else if(month > 8){
		return calc_low();
	}
	if(day <= 2){
		return calc_low();
	}else if(day >= 14){
		return calc_high();
	}
	return -1;
}

int main(){
	int w;
	cin>>month>>day>>year;
	while(month){
		month --;
		w = calc();
		if(w >=0){
			cout<<monthname[month]<<" "<<day<<", "
				<<year<<" is a "<<weekname[w]<<endl;
		} else {
			cout<<(month+1)<<"/"<<day<<"/"<<year
				<<" is an invalid date."<<endl;
		}
		cin>>month>>day>>year;
	}
	
	return 0;
}
