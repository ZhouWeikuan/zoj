#include<cstdio>
#include<cmath>
#include<map>

using namespace std;
int primetable[3520] = {
	2,3,5,7,11,13,17
};
int primenum = 7;
int num;

void init(){
	int n,i,lim, p;
	for(n=19;n< 32768;n+=2){
		lim = (int)sqrt((double)n) + 1;
		p = 1;
		for(i=0;primetable[i]<lim;i++){
			if(n%primetable[i] == 0){
				p = 0;
				break;
			}
		}
		if(p){
			primetable[primenum++] = n;
		}
	}
}
int getInput(){
	int ret = 1;
	int a,b;
	char c;
	do {
		scanf("%d %d%c",&a,&b,&c);
		if(a==0)
			return 0;
		while(b--){
			ret *= a;
		}
	}while(c!='\n');

	return ret;
}

void print(){
	map<int,int> table;
	int i = 0;
	int t = primetable[i];
	while(t <= num){
		while(num%t ==0){
			table[t]++;
			num /= t;
		}
		i ++;
		t = primetable[i];
	}
	t = 0;
	for(map<int,int>::reverse_iterator iter= table.rbegin();
		iter!= table.rend();
		iter++){
		if(t == 0){
			t = 1;
			printf("%d %d", iter->first,iter->second);
		} else {
			printf(" %d %d", iter->first,iter->second);
		}
	}
	printf("\n");
}

int main(){
	init();

	while( 0 != (num = getInput())){
		num--;
		print();
	}

	return 0;
}

