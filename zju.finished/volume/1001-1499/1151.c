#include<stdio.h>

enum {
	Size = 4096,	
};
char buffer[Size];

void reverse(int s, int e){
	int t = (e-s)/2;
	int i;
	char c;
	for(i=0;i<t;i++){
		c = buffer[s+i];
		buffer[s+i] = buffer[e - i-1];
		buffer[e - i-1] = c;
	}
}

void fun(){
    int i = 0,j=1;
    while(buffer[j] != '\n'){
		while(buffer[j] != '\n' && buffer[j] != ' '){
			j++;
		}
		reverse(i,j);
		while(buffer[j] ==' ')
			j++;
		i = j;
		if(buffer[j] != '\n'){
			j = i+1;
		} else {
			break;
		}
	}
	buffer[j] = 0;
	printf("%s\n",buffer);
	
}

int main(){
    int tstcase;
    int i = 0;
    int n;    
    
    scanf("%d",&tstcase);
    while(tstcase --){
		if(i!=0){
			printf("\n");
		}
		i++;
		scanf("%d\n",&n);
		while(n--){
			fgets(buffer,Size,stdin);
			fun();
		}
	}
    
    return 0;
}
