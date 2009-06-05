#include<cstdio>
#include<cstdlib>

using namespace std;
enum {
    SIZ = 40,
};
int xnum, linenum, xline;
char buf[SIZ];

int fun(){
    int i,j;
    xnum = xline = 0;
    int cur = 0;
    for(i=0;i<linenum;i++){
        cur = 0;
        fgets(buf, SIZ, stdin);
        for(j=0; buf[j]; j++){
            if(buf[j] =='X'){
                cur ++;
            } else if(buf[j] ==' '){
                ;
            } else {
                break;
            }
        }
        xnum += cur;
        if(cur > xline)
            xline = cur;
    }
    return linenum *xline - xnum;
}

int main(){
    
    fgets(buf, SIZ, stdin);
    linenum = atoi(buf);
    while(linenum){
        printf("%d\n",fun());
        fgets(buf, SIZ, stdin);
        linenum = atoi(buf);
    }

	return 0;
}
