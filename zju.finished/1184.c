#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int balance;	/* 0 --- even,  1 --- left, 2 --- right */
	int left[12];
	int right[12];
}Node ;

char left[8];
char right[8];
char buffer[12];
Node measure[3];
int pos;

void process(){
	int i;
	int t;
	for(i=0; left[i] ;i++){
		t = left[i] - 'A';
		measure[pos].left[t] = 1;
	}
	for(i=0; right[i] ;i++){
		t = right[i] - 'A';
		measure[pos].right[t] = 1;
	}
	if(strcmp(buffer,"even")==0){
		measure[pos].balance = 0;
	} else if(strcmp(buffer,"up")==0) {
		measure[pos].balance = 1;
	} else {
		measure[pos].balance = 2;
	}
}

int guess(int n){
	int i;
	int status = 0;
	Node *p;
	for(i=0;i<3;i++){
		p = &measure[i];
		if(p->balance == 0){
			if(p->left[n] || p->right[n])
				return 0;
			continue;
		}
		if(!p->left[n] && !p->right[n])
			return 0;
		if(p->balance == 1){
			if(p->left[n]){
				if(status ==0){
					status = 1;
				} else {
					if(status !=1){
						return 0;
					}
				}
			} else {	/*right */
				if(status ==0){
					status = 2;
				} else {
					if(status != 2)
						return 0;
				}
			}
		} else if(p->balance == 2){
			if(p->left[n]){
				if(status ==0){
					status = 2;
				} else {
					if(status !=2){
						return 0;
					}
				}
			} else { /* right */
				if(status==0){
					status = 1;
				} else {
					if(status !=1)
						return 0;
				}
			}
		}
	}
	return status;
}

const char *ans[2] = {	
	"heavy",
	"light"
};

void fun(){
	int i;
	int t;
	for(i=0;i<12;i++){
		t = guess(i);
		if(t){
			break;
		}
	}
	if(! t)
		return;
	i += 'A';
	printf("%c is the counterfeit coin and it is %s.\n",i, ans[t-1]);
}

int main(){
    int tstcase;    
    
    scanf("%d", &tstcase);
    while(tstcase --){
		pos = 0; 
		memset(measure,0,sizeof(Node)*3);		
		while(pos < 3){
			scanf("%s %s %s", left, right,buffer);
			process();
			pos++;
		}
		fun();		
	}
    
    return 0;
}
