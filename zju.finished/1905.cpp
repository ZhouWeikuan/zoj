#include<cstdio>
#include<cstring>
//重复肯定是从错误的开始
using namespace std;
enum {
	N = 1000020,
};
char dat[N];
int pos;

int fun(){
	int cur = 1,t;
	int lim = pos/2;
	char *now;
	while(cur <= lim ){
		t = 0;
		if(pos % cur ==0){
			now = &dat[cur];
			while(dat[t] == now[t] ){
				t ++;
			}
			if(now[t] ==0){
				return pos/cur;
			}
			cur += t;
		} 
		if(!t)
			cur++;
	}
	return 1;
}

int main(){
	
	fgets(dat,N,stdin);
	//cin.getline(dat,N);
	while(dat[0] !='.'){
		pos = strlen(dat);
		dat[--pos] = 0;
		if(pos >= 2){
			pos = fun();
		}
		printf("%d\n",pos);
		fgets(dat,N,stdin);
		//cin.getline(dat,N);
	}

	return 0;
}
