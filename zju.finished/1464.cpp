//二分逼近，先计算最大长度，从中值开始逼近
#include<cstdio>
#include<iostream>

using namespace std;
enum {
	SZ = 10008,
};
int cable[SZ];
int cnum;
int N,K;
long long total;
char buf[10];
int parse(){
	int t = 0;
	for(int i=0;buf[i];i++){
		if(buf[i] =='.')
			continue;
		t *= 10;
		t += buf[i] - '0';
	}
	return t;
}

void readIn(){
	int i;
	total = 0ll;
	for(i=0;i<N;i++){
		cin>>buf;
		cable[i] = parse();
		total += cable[i];
	}
}

int avail(long long s){
	if(s < 1)
		return 0;
	int sum = 0;
	for(int i=0;i<N;i++){
		sum += (int)(cable[i]/s);
	}
	return sum;
}

int fun(){
	long long low = 0, high = total/K + 1, mid;
	int t;
	while(low < high){
		mid = (low + high) / 2;	
		t = avail(mid);
		if(t >= K){//可行
			low = mid + 1;
		} else {//不可行
			high = mid;
		}
	}
	mid = (low + high)/2;
	if(mid >0)
		mid --;
	return (int)mid;
}

int main(){
	int tstnum,t;
	cin>>tstnum;
	while(tstnum --){
		cin>>N>>K;
		readIn();
		t = fun();
		printf("%d.%02d\n", t/100, t%100);
		if(tstnum)
			printf("\n");
	}

	return 0;
}
