#include<cstdio>
//先计算所有乘数，再将它加到被除数上
using namespace std;
enum {
    MaxSize = 500001,
};

int num;
int save[MaxSize] = {0};

void init(){
	int i,j;
	for(i=1;i<=MaxSize/2;i++){
		for(j=i;j<MaxSize;j+=i){
			save[j] += i;
		}
	}
}

int main(){
    int tstcase;    
    int t;
    init();
	scanf("%d ", &tstcase);
    while(tstcase --){
		scanf("%d ", &num);
		if(num <= MaxSize/2){
			t = save[num] - num;
		} else {
			t = save[num];
		}
		printf("%d\n",t);
    }    
    return 0;
}
