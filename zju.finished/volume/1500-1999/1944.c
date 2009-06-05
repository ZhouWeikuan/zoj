#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char pre[30];
char mid[30];

int findplace(char c, int start, int end){
    for( ;start< end; start++){
        if(mid[start] == c){
            return start;
        }
    }
    return -1;
}

void fun(int left, int right, int start, int end){
    int pos, range;
	if(right <= left)
	   return;
	pos = findplace(pre[left], start,end);
	
	range = left+pos - start;
	fun(left+1, range +1, start, pos);
	fun(range+1, right, pos+1,end);
	printf("%c",pre[left]);
}

int main(){
	int len;
	
	scanf("%s %s", pre,mid);
	while(!feof(stdin)){
        len = strlen(pre);
        fun(0,len, 0, len);
        printf("\n");
        scanf("%s %s", pre,mid);
    }
	
	return 0;
}
