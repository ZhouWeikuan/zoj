#include<iostream>
using namespace std;
enum {
    SIZ = 200008,
    MIN = 2,
};
struct Key{
    int r;
    int c;
    Key *rnext;
    Key *cnext;
    bool operator<(const Key &rhs) const {
        if(r != rhs. r){
            return r<rhs.r;
        }
        return c < rhs.c;
    }
};
Key tree[SIZ];
Key *rlink[SIZ];
Key *clink[SIZ];

int row,col, num;
void readIn(){
    scanf("%d%d%d", &row,&col,&num);
    int i;
    for(i=0;i<num;i++){
        scanf("%d%d",&tree[i].r,&tree[i].c);
    }
    sort(tree, tree+num);
    memset(rlink, 0, sizeof(Key*) * (row+4));
    memset(clink, 0, sizeof(Key*) * (col+4));
    for(i=num-1; i>=0; i--){
        tree[i].rnext = rlink[tree[i].r];
        rlink[tree[i].r] = &tree[i];
        
        tree[i].cnext = clink[tree[i].c];
        clink[tree[i].c] = &tree[i];
    }
}

int check_row(){
    int i,pred, ret = 0;
    Key * p;
    for(i=1;i<=row;i++){
        p = rlink[i];
        pred = 0;
        while(p!=NULL){
            if(p->c - pred > MIN){
                ret ++;
            }
            pred = p->c;
            p = p->rnext;
        }
        if(col-pred>=MIN)
            ret ++;
    }
    return ret;
}

int check_col(){
    int i,pred, ret = 0;
    Key * p;
    for(i=1;i<=col;i++){
        p = clink[i];
        pred = 0;
        while(p!=NULL){
            if(p->r - pred > MIN){
                ret ++;
            }
            pred = p->r;
            p = p->cnext;
        }
        if(row-pred>=MIN)
            ret++;
    }
    return ret;
}


int fun(){
    Key k;
    int ret = 0;
    ret += check_row();
    ret += check_col();
    return ret;
}

int main(){
    int tstcase;

    scanf("%d",&tstcase);
    while(tstcase --){
        readIn();
        printf("%d\n",fun());
    }
    
    return 0;
}
