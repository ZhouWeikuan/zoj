#include<stdio.h>
#include<string.h>

char buffer[1024];
char trans[28];

void init(){
    int i;
    for(i=0;i<26;i++){
        trans[i] = 'A' + (i+26-5)%26;
    }
    
}


int main(){
    char *p;
    int t;
    init();
    
    fgets(buffer,1024,stdin); /* start */
    while(strcmp("ENDOFINPUT\n",buffer)!=0){
        fgets(buffer,1024,stdin);
        p = buffer;
        while(*p){
            if( *p >= 'A' && *p <= 'Z' ){
                t = *p - 'A';
                *p = trans[t];
            } 
            p++;
        }
        printf(buffer);
        
        fgets(buffer,1024,stdin); /* end */
        fgets(buffer,1024,stdin); /* start */
    }
    
    return 0;
}
