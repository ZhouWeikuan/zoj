#include<iostream>
using namespace std;
enum {
    SIZ = 104,
};

int main(){
    int num;    
    scanf("%d", &num);
    while(num > 0){
        int l = 1000, h = 0, s=0, t;
        for (int i=0; i<num; ++i){
            scanf("%d", &t);
            l = min(l, t);
            h = max(h, t);
            s += t;
        }
        s -=l; s-=h; num -=2;
        s /= num;
        printf("%d\n", s);
        scanf("%d", &num);
    }

    return 0;
}

