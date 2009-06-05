#include<iostream>
#include<cmath>
using namespace std;

enum {
    SIZ = 50008,
};
int dat[SIZ];
int blk[SIZ];
int num, op, bn, len;

void init(){
    bn  = 0;
    len = (int)sqrt(num) + 1;
    int i;
    for(i=0; i+len < num; i+=len, bn++){
        blk[bn] = dat[i];
        for(int j=0; j<len; j++){
            if(blk[bn] > dat[i+j]){
                blk[bn] = dat[i+j];
            }
        }
    }
    if(i < num){
        blk[bn] = dat[i];
        while(i<num){
            if(dat[i] < blk[bn]){
                blk[bn] = dat[i];
            }
            i++;
        }
        bn++;
    }
}

// find the minimum;
int search(int s, int e){

}

void update(int pos){
    int no = pos / len;
    if(blk[no] > dat[pos]){
        blk[no] = dat[pos];
    }
}
void fun(){
    char type;
    int a,b,k;
    while(op--){
        scanf(" %c %d%d",&type,&a,&b);
        if(type =='C'){
            if(dat[a] > b){
                dat[a] = b;
                update(a);
            } else {
                dat[a] = b;
            }
        } else {
            scanf("%d",&k);
            k = search(a, b);
            printf("%d\n", k);
        }
    }
}

int main(){
    int tstcase;

    scanf("%d ", &tstcase);
    while(tstcase --){
        scanf("%d%d ", &num, &op);
        for(int i=1; i<=num; i++){
            scanf("%d ", &dat[i]);
        }
        init();
        fun();
    }

    return 0;
}

