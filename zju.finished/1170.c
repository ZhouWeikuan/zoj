#include<stdio.h>

char left[1024];
char right[1024];

int gcd(int a, int b){
	int t;
	
	while(b > 0){
		t = a%b;
		a = b;
		b = t;	
	}	
	return a;
}


void fun(){
	int max = 0;
	int t;
	int i,j;
	int a,b;
	
	for(i=0; left[i]; i++){		
		for(j=0; right[j]; j++){
			t = 0;
			a = i, b = j;
			while(left[a] && right[b]){
				t += left[a] == right[b];
				a ++, b++;
			}
			if( t > max){
				max = t;
			}
		}		
	}
	t = i + j;
	max *= 2;
	
	if( max ==0){
		printf("appx(%s,%s) = 0\n", left, right);
		return ;	
	}
	
	i = gcd(t, max);
	max /= i;
	t /= i;
	if( max != t)
		printf("appx(%s,%s) = %d/%d\n", left, right, max, t);
	else 
		printf("appx(%s,%s) = 1\n", left, right);
}

int main(){    
    
    scanf("%s", left);    
    while(left[0] !='-'){
		scanf("%s", right);
		fun();
		
		scanf("%s", left);
	}
    
    return 0;
}
