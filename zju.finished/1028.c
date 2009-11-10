#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 30,
};

int  ball[Size];
int  num;
int  count[2];
/*
 搜索？太慢了,所以只能用构造的方法.考虑两个相邻的白盘子,我们可以把它们随意移动,而且它们也不会阻碍单个白盘子的运动。比如：

 b-b-w-w =>b-w-w-b w-w-b-w-b => b-w-w-w-b => w-b-b-w-w-b(这一串变化就相当于把右面的单个白盘子移到了左边）

 这样，我们就可以把两个连在一起的白盘子拿掉而不影响结果，一旦只剩一个白盘子，就达到了目的。这样编程已经可以达到要求了。但是还有更好用的结论。

 结论1：如果有奇数个盘子，那么总能达到目标。证明：考虑两个白盘子，它们之间的距离加上1如果是奇数，就可以移动到一起。设N(k)是第k个盘子与第k+ 1个盘子的距离加1，不难看出N(1)+N(2)+...+N(n)就是盘子的个数，是一个奇数，所以N(k)中至少有一个奇数，这样就可以拿掉那两个盘子。

 结论2：如果有偶数个盘子，当且仅当奇数位上白盘子数和偶数位上白盘子数相差1以内才能达到目标。（证明略，用染色或者上面的结论都可以）
 */

int fun(){
	int i;
	if(num %2 )
		return 1;
	count[0] = count[1] = 0;
	for(i=0;i<num;i++){
		if(ball[i] ==0){
			count[i%2]++;
		}
	}
	i = count[0] - count[1];
	
	return (i <2 && i >-2);		
}

int main(){
	int tstcase,i;

	scanf("%d",&tstcase);
	while(tstcase--){
		scanf("%d", &num);
		for(i=0;i<num;i++){
			scanf("%d",&ball[i]);
		}
		if(fun()){
			printf("YES\n");
		}else {
			printf("NO\n");
		}
	}	

	return 0;
}
