#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int pos;
	int coff[2008];	
} Poly ;

Poly first,second,third;

void mult(Poly *result , Poly *a, Poly *b){
	memset(result, 0, sizeof(Poly));
	result->pos = a->pos -1 + b->pos;
	int i,j,t;
	
	for(i=a->pos-1;i>=0; i--){
		if(a->coff[i] ==0 )
			continue;
		for(j=b->pos-1;j>=0;j--){
			if(b->coff[j] ==0 )
				continue;			
			 
			result->coff[i+j] = 1 - result->coff[i+j];
		}
	}
}

void mod(Poly *a, Poly *b){
	int i,j,t;
	
	for(i=a->pos-1;i>=b->pos-1;i--){
		if(a->coff[i] == 0)
			continue;
		t = i - b->pos+1;
		for(j=b->pos-1;j>=0;j--){
			if(b->coff[j] == 0)
				continue;
			if(a->coff[t + j] == 1){
				a->coff[t + j] = 0;
			} else {
				a->coff[t + j] = 1;
			}
		}
	}
	i = b->pos-2;
	while(i>=0){
		if(a->coff[i] == 1)
			break;
		i--;
	}
	a->pos = i+ 1;
	if(a->pos <=0) {
		a->pos = 1;		
	}
}

void output(Poly *a){
	int i;
	printf("%d", a->pos);
	for(i=a->pos-1;i>=0; i--){
		printf(" %d", a->coff[i]);	
	}
	printf("\n");
}

void get_input(Poly *a){
	int i;
	scanf("%d", &a->pos);
	for(i=a->pos-1;i>=0;i--){
		scanf("%d", &a->coff[i]);
	}
}

int main(){
    int tstcase;
    
    scanf("%d", &tstcase);
    
    while(tstcase --){
		get_input(&first);
		get_input(&second);
		mult(&third, &first, &second);
		get_input(&first);
		mod(&third,&first);
		output(&third);
	}
    
    return 0;
}
