#include<stdio.h>
#include<math.h>

int num;
int data[60];

int gcd(int a, int b){
	int t;
	while(b > 0){
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}
int comp(int *a, int *b){
	return *a - *b;
}

void fun(){
    int i,j;
    double sum = num * (num-1)/2;
    qsort(data,num,sizeof(int),(int(*)(const void*,const void*))comp);
    
    int t = 0;
    for(i=0;i<num-1;i++){
		for(j=i+1;j<num;j++){
			if(gcd(data[j],data[i])==1){
				t ++;
			}
		}
	}
    if(t ==0){
		printf("No estimate for this data set.\n");
		return ;
	}
	sum *= 6;
	sum /= t;
	sum = sqrt(sum);
	printf("%.6lf\n",sum);
}

int main(){
    int i;
    
    scanf("%d",&num);
    while(num){
		for(i=0;i<num;i++){
			scanf("%d",&data[i]);
		}
		fun();
		scanf("%d",&num);
	}
    
    return 0;
}
