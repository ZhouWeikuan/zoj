#include<iostream>
using namespace std;
enum {
    SIZ = 40,
};
unsigned val;
struct Point{
    unsigned x,y;
};
int pos;
Point pa[SIZ];

// the current value is cur, get the biggest available exp for 3 first
// and then the reminder is dividable by 2, so we divide it by 2
void test(){
    unsigned i, two=0, tri=0,t;
    pos = 0;
    while(val > 0){
        while(val%2==0){ // get coefficient for 2
            val /= 2;
            two++;
        }
        for(tri=0,t=1; t<val; tri++, t*=3)
            ;
        while(t>val||(val-t)%2!=0) {
            tri--;
            t/=3;
        }
        val -= t;
        pa[pos].x = two;
        pa[pos].y = tri;
        pos++;
    }
}
void fun(){
    test();
    printf(" %d",pos);
    for(int i=0; i<pos; i++){
        printf(" [%u,%u]", pa[i].x, pa[i].y);
    }
    printf("\n");
}
int main(){
    int tst=0, tstnum;
    scanf("%d", &tstnum);
    while(tst++<tstnum){
        printf("%d", tst);
        scanf("%u", &val);
        fun();
    }
    return 0;
}

