#include<iostream>

using namespace std;

void reverse(int k){
	static char buf[20], top;
	top = 0;
	while(k){
		buf[top++] = k%10 +'0';
		k /= 10;
	}
	buf[top] = 0;
	cout<<buf;
}

void fun(int n){
	int val = 9;
	int space = 1;
	for(;;){ // 计算位数，各位分别有9,9,90,90,900,900...位palidrome 
		if(n <= val){
			break;
		}
		n -= val;
		space ++;
		if(n <= val){
			break;
		}
		n -= val;
		space ++;
		val *= 10;
	}
	if(space > 1)
		n--;
	if(space %2 ==0){ //even
		space /= 2;
		val = 1;
		while(--space){
			val *= 10;
		}
		val += n;
		cout<<val;
		reverse(val);
		cout<<endl;
	} else if(space ==1){
		cout<<n<<endl;
	} else {//odd
		space /= 2;
		val = 1;
		while(--space){
			val *= 10;
		}
		val += n/10;
		cout<<val<<(n%10);
		reverse(val);
		cout<<endl;
	}
}

int main(){
	int num;

	cin>>num;
	while(num){
		fun(num);
		cin>>num;
	}

	return 0;
}
