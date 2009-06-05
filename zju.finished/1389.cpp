#include<iostream>
using namespace std;
// 离散化方法
enum {
    SIZ = 50004*2,
};
struct Box{
    int h, a; // high and area
    bool operator<(const Box&rhs)const{
        return h<rhs.h;
    }
};
int num, vol;
Box box[SIZ];

void fun(){
    int hei = box[0].h, i, area=0;
    for(i=0;i<num;i++){
        if(box[i].a == 0) continue;
        if(vol > area*(box[i].h-hei)){
            vol -= area*(box[i].h-hei);
            area += box[i].a;
            hei = box[i].h;
        } else {
            break;
        }
    }
    if(vol > (box[num-1].h - hei)*area){
        printf("OVERFLOW\n");
        return;
    }
    double v = vol;
    v /= area;
    v += hei;
    printf("%.2lf\n", v);
}

void readIn(){
    int b, h, w, l, i;
    scanf("%d", &num);
    for(i=0; i<num; i++){
        scanf("%d%d%d%d",&b,&h,&w,&l);
        w *= l;
        h += b;
        box[2*i].h = b;
        box[2*i].a = w;
        box[2*i+1].h = h;
        box[2*i+1].a = -w;
    }
    num *= 2;
    sort(box, box+num);
    scanf("%d", &vol);
}

int main(){
    int tst;

    scanf("%d", &tst);
    while(tst--){
        readIn();
        fun();
    }
    return 0;
}
