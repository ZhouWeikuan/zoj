#include<iostream>
#include<set>
#include<cmath>
using namespace std;

set<int> table;

int isprime(int n){
	set<int>::iterator iter = table.begin();
	int lim = (int)sqrt((double)n) + 1;
	for( ; iter!= table.end() && *iter < lim; iter++){
		if(n % (*iter) ==0)
			return 0;
	}
	return 1;
}

void init(){
	int i;
	table.insert(2);
	table.insert(3);
	table.insert(5);
	
	for(i=7;i<100000;i+= 2){
		if(isprime(i) ){
			table.insert(i);
		}
	}
}

int getsum(int n){
	int s = 0;
	while(n > 0){
		s += n % 10;
		n /= 10;
	}
	return s;
}

int calc(int n){
	set<int>::iterator iter;
	int orig_sum = getsum(n);
	int sum = 0;
	int lim = (int) sqrt((double)n) + 1;
	int flag = 0;
	int prime = 1;
	for(iter = table.begin(); iter!= table.end() && *iter < lim; iter ++){		
		while(n % (*iter) ==0){
			sum += getsum(*iter);
			n /= (*iter);
			flag = 1;
			prime = 0;
		}
		if(flag ){
			flag = 0;
			lim = (int) sqrt((double)n) + 1;
		}
	}
	if(prime)
		return 0;
	if(n != 1)
		sum += getsum(n);
	return sum==orig_sum;
}

int fun(int n){
	int t;
    for(;;){
		t = calc(n);
		if(t)
			return n;
		n++;
	}
    return 0;
}

int main(){
	int num;
	
    init();
    cin>> num;
    while(num > 0){
		num ++;
		num = fun(num);
		cout<<num<<endl;
		cin>> num;
	}
    return 0;
}
