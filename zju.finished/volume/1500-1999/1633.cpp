#include<iostream>
#include<map>

using namespace std;
typedef unsigned long long uint64_T;

uint64_T table[90];
int pos;
const string orig = "T.T^__^T.T";
uint64_T num;

int search(){
	int hi = pos, low = 0;
	int mid;
	while(hi > low){
		mid = (hi+low)/2;
		if(table[mid] < num){
			low = mid + 1;
		} else if(table[mid] > num){
			hi = mid;
		} else {
			break;
		}
	}
	if(hi == low)
		mid = low;
	if(table[mid] <= num)
		mid ++;
	return mid;
}

void fun(){
	int d;
	if(num < 10llu){
		cout<<orig[num]<<endl;
		return;
	}
	d = search();
	while(d > 1){
		if(table[d-1] > num ){
			d = d- 1;
		} else {
			num -= table[d-1];
			d = d-2;
		}
	}
	cout<<orig[num]<<endl;
	return;
}

int init(){
	pos = 0;
    uint64_T a = 4ll;
    uint64_T b = 3ll;
    uint64_T c = 0;
    uint64_T lim = 1ll;
    lim <<= 63;
    
    while(c < lim){
		c = b + a;
		a = b;
		b = c;
		table[pos++] = c;		
	}    
}

int main(){		
    init();
    
    while(cin>>num){		
		num --;	
		fun();		
	}
    
    return 0;
}
