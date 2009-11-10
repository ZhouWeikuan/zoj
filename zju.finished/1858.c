#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 24,	
};

char alpha[26] = {
	0,		/* A */
	'1',    /* B */
	'2',	/* C */
	'3',	/* D */
	0,		/* E */
	'1',	/* F */
	'2',	/* G */
	0,		/* H */
	0,		/* I */
	'2',	/* J */
	'2',	/* K */
	'4', 	/* L */
	'5',	/* M */
	'5',	/* N */
	0,		/* O */
	'1',	/* P */
	'2',	/* Q */
	'6',	/* R */
	'2',	/* S */
	'3',	/* T */
	0,		/* U */
	'1',	/* V */ 
	0,		/* W */
	'2',	/* X */
	0,		/* Y */
	'2'		/* Z */
};

char buffer[Size];

int fun(){
    int i;
    int t;
    int pred = -1;
    int j = 0;
    for(i=0; buffer[i]; i++){
		t = buffer[i] - 'A';
		if(alpha[t] && alpha[t] != pred){			
			buffer[j++] = alpha[t];			
		}
		pred = alpha[t];
	}
	buffer[j] = 0;
	printf("%s\n",buffer);
}

int main(){
    
    scanf("%s", buffer);
    while(!feof(stdin)){
		fun();
		scanf("%s", buffer);
	}
    
    return 0;
}
