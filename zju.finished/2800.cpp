#include<iostream>
using namespace std;
enum {
    SIZ = 208,
};
int len;
char word[SIZ];
char lst[SIZ][SIZ];
char mat[SIZ][SIZ];

bool isSet(int,int);
bool isOne(int s, int e){
    return s==e;
}
bool isNone(int s, int e){
    return e<s;
}
// element number for list is at least 2
bool atLeast2(int s, int e){
    if(lst[s][e]!=-1) return lst[s][e];
    int i;
    for(i=s+1; i<e; i++){
        if(word[i]!=',') continue;
        if(!isOne(s,i-1) && !isSet(s,i-1)){
            continue;
        }
        if(isOne(i+1,e)||isSet(i+1,e)||atLeast2(i+1,e))
            return lst[s][e] = true;
    }
    return lst[s][e]=false;
}

// whether is is a set
bool isSet(int s,int e){
    if(mat[s][e]!=-1)
        return mat[s][e];
    if(s>=e||word[s]!='{' || word[e]!='}')
        return mat[s][e] = false;
    return mat[s][e] = isNone(s+1,e-1)||isOne(s+1,e-1)
                        ||isSet(s+1,e-1)||atLeast2(s+1,e-1);
}
bool fun(){
    len = strlen(word)-1;
    memset(lst, -1, sizeof(lst));
    memset(mat, -1, sizeof(mat));
    return isSet(0, len);
}

int main(){
    int tst, n=1;
    scanf("%d", &tst);
    while(tst--){
        printf("Word #%d: ", n++);
        scanf("%s", word);
        if( !fun()){
            printf("No ");
        }
        printf("Set\n");
    }
    return 0;
}

