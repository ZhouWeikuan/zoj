#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int table[32780];
int square[182];
void init(){
	int i,j,m,n;
	int t;
	for(i=1;i<182;i++){
		square[i] = i * i;
	}
	for(i=1;i<182;i++){
		t = square[i];
		if(t < 32780)
			table[t]++;
		for(j=i;j<182;j++){
			t = square[i] + square[j];
			if(t < 32780)
				table[t]++;
			else 
				break;
			for(m=j;m<182;m++){
				t = square[i] + square[j] + square[m];
				if(t < 32780)
					table[t] ++;
				else
					break;
				for(n=m;n<182;n++){
					t = square[i] + square[j] + square[m] + square[n];
					if(t < 32780)
						table[t] ++;
					else
						break;
				}
			}
		}
	}
}

int main(){
    init();
	int num;
	
	scanf("%d", &num);
	while(num > 0){
		printf("%d\n", table[num]);
		scanf("%d", &num);
	}
    
    return 0;
}
