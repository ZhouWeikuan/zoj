#include<iostream>

using namespace std;
enum {
    LZ = 108,
    SIZ = 100008,
};
const double MaxNum = 1e20;
struct Node {
    int n;
    double p;
};
int num, len;
Node tree[SIZ];
int dat[LZ];
double tab[2][LZ];

void readIn(){
    int i;
    for(i=0;i<len;i++){
        scanf("%d ", &dat[i]);
    }
    for(i=0;i<num;i++){
        scanf("%d%lf ", &tree[i].n, &tree[i].p);
    }
}

void fun(){
    int i,j;
    double *pred=tab[0], *curr=tab[1], *tmp;
    for(i=0;i<len;i++){
        pred[i] = MaxNum;
    }
    pred[i] = 0;
    for(i=num-1;i>=0;i--){
        curr[len] = 0;
        for(j=len-1;j>=0;j--){
            if(dat[j] != tree[i].n ){ 
                curr[j] = pred[j];
                continue;
            }
            curr[j] = tree[i].p + pred[j+1];
            if(curr[j] > pred[j]){
                curr[j] = pred[j];
            }
        }
        tmp = pred; pred = curr; curr = tmp;
    }

    if(pred[0] >= MaxNum){
        printf("Impossible\n");
    } else {
        printf("%.2lf\n", pred[0]);
    }
}

int main(){
    
    scanf("%d%d ", &len, &num);
    while(len + num){
        readIn();
        fun();
        scanf("%d%d ", &len, &num);
    }

	return 0;
}
