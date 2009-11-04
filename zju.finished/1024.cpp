#include<iostream>
#include<queue>
#include<map>
using namespace std;

map<int, int> record;
int table[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int leapyear(int year){
	if(year % 4 == 0 && year %100 !=0)
		return 1;
	if(year %100 ==0 && year % 400 ==0)
		return 1;
	return 0;
}

int getnextmonth(int y, int m, int d){
	int key;
	
	if(m == 1){
		key = 28;
		key += leapyear(y);
		if(d>key){
			return -1;
		}
		m++;
	} else if(m == 12){
		y++; m = 1;		
	} else {
		key = table[m+1];
		if(d > key){
			return -1;
		}
		m ++;
	}
	if(y > 2001 || (y==2001 && m>11) || (y==2001 && m==11 && d >4) ){
		return -1;
	}
	
	key = (y << 16) + (m << 8) + d;
	return key;
}

int getnextdate(int y, int m, int d){
	int key = table[m];
	key += (m==2 && leapyear(y));
	if(d < key){
		d ++;
	} else {
		if(m== 12){
			y ++; m = 1; d = 1;			
		} else {
			m ++; d= 1;
		}
	}
	if(y > 2001 || (y==2001 && m>11) || (y==2001 && m==11 && d >4) ){
		return -1;
	}
	
	key = (y<<16) + (m <<8) + (d);
	return key;
}


int calc(int year, int month, int day){    
    int key;
    int nextkey;
	map<int,int>::iterator iter;
	
    key = (year<<16) + (month<<8) + (day);
    iter = record.find(key);
    if(iter != record.end() ){
		return iter->second;
	}
    
    nextkey = getnextmonth(year,month,day);
    if(nextkey != -1){
		if(0 == calc(nextkey>>16, (nextkey>>8) &0xff, nextkey&0xff)){
			record[key] = 1;
			return 1;
		}		
	}
    
    nextkey = getnextdate(year,month,day);
    if(nextkey != -1){
		if(0 == calc(nextkey>>16, (nextkey>>8) &0xff, nextkey&0xff)){
			record[key] = 1;
			return 1;
		}		
	}
    
    record[key]  = 0;
    return 0;
}

int main(){
	int tstcase;
	int year,month, day;    
    
    year = 2001, month = 11, day = 4;
    year = (year<<16) + (month<<8) + (day);
    record[year] = 0;
    
    cin>>tstcase;
    while(tstcase --){
		cin>>year>>month>>day;
		if( calc(year,month,day) ){
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}		
	}
	
    return 0;
}
