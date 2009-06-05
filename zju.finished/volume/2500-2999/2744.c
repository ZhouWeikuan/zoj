#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum {
	Size = 5008,
};

char buffer[Size];
int  num;

int palin(int mid){
	int ret = 1;
	int left = mid -1, right = mid+1;
	/*calc the odd number centered by mid */
	while(left>=0 && right <num){
		if(buffer[left] == buffer[right]){
			ret ++;
		}else {
			break;
		}
		left--, right++;
	}

	/* calc the even number */
	left = mid, right =mid +1;
	while(left>=0 && right <num){
		if(buffer[left] == buffer[right]){
			ret ++;
		} else {
			break;
		}
		left--,right++;
	}
	return ret;
}

int fun(){
	int i;
	int ret = 0;
	for(i=0;i<num;i++){
		ret += palin(i);
	}
	return ret;
}

int main(){
	int ret;
	scanf("%s", buffer);
	while(!feof(stdin)){
		num = strlen(buffer);
		ret = fun();
		printf("%d\n", ret);
		scanf("%s", buffer);
	}

	return 0;
}
