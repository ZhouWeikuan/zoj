#include<iostream>
// 要用到egcd...
using namespace std;
int x,y,m,n,l;

int fun(){
    int speed = m - n;
    int s;
    if(speed > 0){
        s = (y - x + l)%l;
    } else {
        s = (x - y + l)%l;
        speed = -speed;
    }
    if(speed == 0) return -1;
    if(s%speed!=0 && l%speed==0)
        return -1;
    x = 0;
    while(s > 0){
        x += s / speed;
        s %= speed;
        if(s != 0){
            s += l;
        }
    }
    return x;
}

int main(){

    while(scanf("%d%d%d%d%d",&x,&y,&m,&n,&l) > 0){
        int t = fun();
        if(t < 0){
            printf("Pat\n");
        } else {
            printf("%d\n", t);
        }
    }
    return 0;
}

