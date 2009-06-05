#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cube[10];
int num;

void init(){
	int i;
	for(i=0;i<10;i++){
		cube[i] = i*i*i;
	}
}

int fun(){
    int n = num;
    int t;
    int value = 0;
    
    while(n){
		t = n%10;
		n /= 10;
		value += cube[t];
	}
    return (value == num);
}

const char *ans[2] = {
	"No",
	"Yes"
};

int main(){
    
    init();
    scanf("%d", &num);
    while(!feof(stdin)){
		num = fun();
		printf("%s\n", ans[num]);
		scanf("%d", &num);
	}
    
    return 0;
}
