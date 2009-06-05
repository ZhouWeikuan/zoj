#include<cstdio>
#include<cstring>
#include<cstdlib>
// 是DP题
using namespace std;
enum {
    SIZ = 10004,
    VAL = (-1u>>2),
};
int pig[SIZ];
struct Coin {
    int w;
    int v;
};
Coin coin[504];
int cnum;
int wei;

int divcmp(const Coin *a, const Coin*b){
    return a->v * b->w - a->w * b->v;
    //return a->v - b->v;
}

int calc(int w){
    if(w < 0){
        return  VAL;
    }
    if(pig[w] >= 0)
        return pig[w];
    int val = VAL, t;
    for(int i=0;i<cnum;i++){
        //if( w % coin[i].w == 0){
        //    t = w / coin[i].w * coin[i].v;
        //} else {
            t = calc(w - coin[i].w) + coin[i].v;
        //}
        if(val > t)
            val = t;
    }
    return pig[w] = val;
}

int fun(){
    int t;
    memset(pig, -1, sizeof(pig));
    pig[0] = 0;
    t = calc(wei);
    if(t >= VAL)
        return -1;
    return t;
}

int main(){
    int tstcase;
    int a,b;
    scanf("%d",&tstcase);
    while(tstcase --){
        scanf("%d%d",&a,&b);
        wei = b - a;
        scanf("%d",&cnum);
        for(a=0;a<cnum;a++){
            scanf("%d%d",&coin[a].v, &coin[a].w);
        }
        qsort(coin, cnum, sizeof(Coin), 
                (int(*)(const void*,const void*))divcmp);

        a = fun();
        if(a < 0){
            printf("This is impossible.\n");
        } else {
            printf("The minimum amount of money in the piggy-bank is %d.\n", a);
        }
    }

	return 0;
}
