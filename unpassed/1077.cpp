#include<iostream>
using namespace std;
// Wrong Answer
enum {
    SIZ = 20,
};
struct Node {
    int sym[4];
};
int num;
Node up[80];
Node dn[80];
unsigned ptr[SIZ];
unsigned rev[SIZ];
unsigned rec[SIZ];
unsigned perm[4];

void output(){
    int i;
    for(i=0; i<20; i++){
        if(i && i%5==0) printf("\n");
        else if(i) printf(" ");
        printf("%c-", i+'A');
        if(rec[i]==(unsigned)-1){
            printf("?");
        } else {
            printf("%c", rec[i]+'a');
        }
    }
    printf("\n");
}
bool item_chk(const Node&a, const Node&b){
    int i;
    unsigned t;
    for(i=0; i<4; i++){
        t = b.sym[perm[i]];
        if(ptr[a.sym[i]] == (unsigned)-1 && rev[t] == (unsigned)-1){
            ptr[a.sym[i]] = t;
            rev[t] = a.sym[i];
        } else if(ptr[a.sym[i]] != t || rev[t] != a.sym[i]){
            return false;
        }
    }
    return true;
}
bool check(){
    memset(ptr, -1, sizeof(ptr));
    memset(rev, -1, sizeof(rev));
    for(int i=0; i<num; i++){
        if(!item_chk(up[i], dn[i]))
            return false;
    }
    return true;
}
void makeup(int s, int e){
    int t, v=0, r;
    for(t=s; t<e; t++){
        v += (rec[t]==(unsigned)-1);
    }
    if(v!=1) return;
    for(; s<e; s++){
        if(rec[s]==(unsigned)-1){
            t = s;
        } else {
            r = rec[s]/5;
        }
    }
    e = (r+1)*5;
    for(s=r*5; s<e; s++){
        if(rev[s]==(unsigned)-1){
            rec[t] = s;
            rev[s] = t;
        }
    }
}
void fun(){
    bool flag = false;
    int i;
    do{
        if(check()){ // prevent multiple possibility.
            if(flag == false){
                flag = true;
                memcpy(rec, ptr, sizeof(ptr));
                for(int i=0; i<4; i++){
                    makeup(i*5, (i+1)*5);
                }
            } else {
                for(i=0; i<SIZ; i++){
                    if(rec[i]!=ptr[i]){
                        rec[i] = -1;
                    }
                }
            }
        }
    }while(next_permutation(perm, perm+4));
    output();
}
int readIn(){
    scanf("%d", &num);
    if(num == 0) return 0;
    int i,j;
    static char buf[10];
    for(i=0; i<num; i++){
        scanf("%s", buf);
        for(j=0; j<4; j++){
            up[i].sym[j] = buf[j] - 'A';
        }
    }
    for(i=0; i<num; i++){
        scanf("%s", buf);
        for(j=0; j<4; j++){
            dn[i].sym[j] = buf[j] - 'a';
        }
    }
    for(i=0; i<4; i++){
        perm[i] = i;
    }
    return 1;
}

int main(){
    int tst=0;
    while(readIn()>0){
        printf("Test #%d:\n", ++tst);
        fun();
    }
    return 0;
}

