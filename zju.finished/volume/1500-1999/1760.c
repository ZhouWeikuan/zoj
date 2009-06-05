#include<stdio.h>


int member[120];
int input[20];
int pos;
int comp(const int*a, const int *b){
	return *a - *b;
}
int fun(){
    qsort(input,pos,sizeof(int),comp);
    int i;
    int sum = 0;
    for(i=0;i<pos;i++){
		if(member[input[i]]){
			sum += 1;
		}
	}
    printf("%d\n",sum);
}

int main(){	
	int num;    
	int t;
	
	scanf("%d",&num);
	while(num >0){		
		pos = 0;
		memset(member,0,sizeof(int)*120);
		while(num !=0){
			input[pos ++] = num;
			t = num * 2;
			if(t < 100)
				member[t] = 1;
			scanf("%d",&num);
		}
		fun();
		
		scanf("%d",&num);
	}
    
    
    return 0;
}
