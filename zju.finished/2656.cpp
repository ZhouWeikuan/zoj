#include<cstdio>

// 相当于求从哪个数开始，所有数的和一直是非负的
// 因此条件如下：
// 1. 所有数的和必须是非负的
// 2. 从0开始计数，如果出现数为负的情况，从下一个再重新计数
// 3. 如果从某个数开始直到最后，和一直为非负，则它是出发点
// 4. 因为有条件1保证，因此不需要再回溯，与前面的数比较
using namespace std;
enum {
	Size = 10004,
};
int num;
int pot[Size];

int fun(){
	int s,i,now;// (now)current sum
    now = 0; s = 0;
	for(i = 0;i<num;){
        now += pot[i];
        i++;
        if(now < 0){
            s = i;
            now = 0;
        }
	}
    if(s < num){
        return s;
    }
    return -1;
}

int main(){
	int t,s;	
	while(scanf("%d",&num)>0){
        s = 0;
		for(int i=0;i<num;i++){
			scanf("%d%d", &pot[i], &t);
			pot[i] -= t;
            s += pot[i];
		}
		num = (s<0)?-1:fun();
		if(num < 0){
			printf("impossible\n");
		} else {
			printf("%d\n",num);
		}
	}

	return 0;
}
