#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char username[84];
	char partyname[84];
	int count;
} Node;

Node candi[24];
int usernum;
int maxnum;
int maxpos ;

int main(){    
	int i;
	char username[84];
	int votenum;
	
    scanf("%d\n",&usernum);
    while(!feof(stdin)){
		maxnum = 0;
		maxpos = -1;
    	for(i=0;i<usernum;i++){
        	fgets(candi[i].username, 84,stdin );
        	fgets(candi[i].partyname, 84,stdin);
        	candi[i].count = 0;        	
    	}
    	scanf("%d\n",&votenum);
    	while(votenum -- ){
        	fgets(username, 84, stdin );
        	for(i=0;i<usernum;i++){
				if(strcmp(candi[i].username, username) == 0){
					candi[i].count ++;
					if(candi[i].count > maxnum){
						maxnum = candi[i].count;
						maxpos = i;
					} else if( candi[i].count == maxnum){
						maxpos = -1;						
					}
					break;
				}
			}
    	}
    
    	if(maxpos == -1){
        	printf("tie\n");
    	} else {        	
			printf("%s", candi[maxpos].partyname);	        
    	}
    	scanf("%d\n",&usernum);
	}
    
    return 0;
}
