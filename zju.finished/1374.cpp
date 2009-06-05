#include<iostream>

using namespace std;
enum {
    SIZ = 108,
};
char words[SIZ][SIZ];
int num, minlen;
char *pw;
void readIn(){
    int len;
    cin>>num;
    cin>>words[0];
    pw = words[0];
    minlen = strlen(pw);
    for(int i=1;i<num;i++){
        cin>>words[i];
        len = strlen(words[i]);
        if(len < minlen){
            pw = words[i];
            minlen = len;
        }
    }
}

int match(int s, int n){
    static char part[2][SIZ];
    int i,j;
    strncpy(part[0], pw + s, n);
    part[0][n] = 0;
    part[1][n] = 0;
    for(i=0,j=n-1;i<n;i++,j--){
        part[1][i] = part[0][j];
    }
    for(i=0;i<num;i++){
        if(strstr(words[i], part[0]) == NULL 
            && strstr(words[i], part[1]) == NULL){
            return 0;
        }
    }
    return n;
}

int fun(){
    int len = minlen;
    int i,t;
    while(len > 0){
        for(i=0;i+len<=minlen;i++){
            if( match(i,len) ){
                return len;
            }
        }
        len --;
    }
    return 0;
}

int main(){
    int tstcase;
    cin>>tstcase;
    while(tstcase --){
        readIn();
        cout<<fun()<<endl;
    }

	return 0;
}
