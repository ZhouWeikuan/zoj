#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int para[10];
int pnum;
char leaf[1024];
char buffer[10];

void fun(){
    int n;
    int hi,low;
    int i;
    int t;
    
    scanf("%d ", &n);
    while(n--){
		hi = 1<<pnum;
		low = 0;
		scanf("%s", buffer);
		for(i=0;i<pnum;i++){
			t = buffer[para[i]] - '0';
			if(t){
				low = (low + hi)/2;
			} else {
				hi = (low+hi)/2;
			}
		}
		printf("%c", leaf[low]);
	}
	
	printf("\n");
}

int main(){
    int i;
    char c,p;
    int tstcase = 0;
        
    scanf("%d ", &pnum);
    while(pnum ){
		for(i=0;i<pnum;i++){
			scanf("%c%c ", &p, &c);
			para[i] = c - '1';			
		}
		scanf("%s ", leaf);
		tstcase ++;
		printf("S-Tree #%d:\n", tstcase);
		fun();
		printf("\n");
		scanf("%d ", &pnum);
	}
    
    return 0;
}
