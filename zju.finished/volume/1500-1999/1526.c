#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int data[100];
int seq[100];
int pos;

int MyComp(const int *a, const int *b){
	return data[*a] - data[*b];
}

int main(){
    int num;
	double sum = 0.0;
	int i,cur=0;
	pos = 0;
    scanf("%d", &num);
    while(num --){
        scanf("%d", &data[pos]);
		seq[pos] = pos;
		pos++;
    }
	qsort(seq,pos,sizeof(int), MyComp);
	num = data[seq[pos-1]];
	for(i=1;i<=num;i++){
		sum += log10(i);
		while(i== data[seq[cur]]){
			data[seq[cur]] = sum + 1;
			cur++;
		}
	}
	for(i=0;i<pos;i++){
		printf("%d\n",data[i]);
	}
    
    return 0;   
}
