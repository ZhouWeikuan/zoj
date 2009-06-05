#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum {
	Size = 100,	
};

char from[Size];
char to[Size];
int fbase, tbase;

int fromchar(char c){
    if( c >='0' && c <='9'){
        return c-'0';
    }
    return c-'A' + 10;
}

char tochar(int t){
    if( t < 10)
        return t +'0';
    return t-10 +'A';
}

int fun(){
	int i;
	int result;
	
	result = fromchar(from[0]);
	for(i = 1; from[i] ;i ++){
        result *= fbase;
        result += fromchar(from[i]);
    }
    
    int end=98;
    to[end+1] = 0;
    int start = end;
    do {
        to[start--] = tochar(result % tbase);
        result /= tbase;
        
    } while( result );
    if(end - start > 7){
         printf("%7s\n","ERROR");
         return -1;
    }
	start ++;
	printf("%7s\n", &to[start]);
	return 0;
}

int main(){
	
	scanf("%s %d %d", from, &fbase, &tbase);
	while(! feof(stdin) ){
        fun();
                
        scanf("%s %d %d", from, &fbase, &tbase);
    }
	
	return 0;
}
