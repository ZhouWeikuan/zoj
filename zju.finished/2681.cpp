#include<iostream>
using namespace std;

int h, w;
int x, y;
int pos;
char ans[1000];

int compute(int bx, int by){
    int t = h*abs(bx - x) - w*abs(by -y);
    if(t < 0){
        return 0;
    } else if(t > 0){
        return 1;
    }
    return 2;
}

void fun(){
    int bx = 1, by = 1;
    x = y = 0;
    pos = 0;
    for(;;){
        int t = compute(bx, by);
        if(t == 0){ // for x
            x = 2 * bx - x;
            ans[pos++] = (bx==0?'W':'E');
            bx = 1 - bx;
        } else if(t == 1){ // for y;
            y = 2 * by - y;
            ans[pos++] = (by==1?'N':'S');
            by = 1 - by;
        } else { // in hole;
            if(bx==0){
                ans[pos++] = '1' + (by==0?0:3);
            } else {
                ans[pos++] = '1' + (by==0?1:2);
            }
            ans[pos] = 0;
            break;
        }
    }
    printf("%d\n%c", pos-1, ans[0]);
    for(x=1; x<pos; x++){
        printf(" %c", ans[x]);
    }
    printf("\n");
}

int main(){
    int tstcase;
    scanf("%d",&tstcase);
    while(tstcase -- ){
        scanf("%d%d",&h,&w);
        fun();
    }
    return 0;
}

