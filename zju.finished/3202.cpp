#include<iostream>
using namespace std;
int high, low, hp, num, tmp;

int main(){
    int tst;

    scanf("%d", &tst);
    while(tst-- > 0){
        scanf("%d",&num);
        scanf("%d", &high);
        low = 0, hp = 1;
        for (int i=2; i<=num; ++i){
            scanf("%d",&tmp);
            if (tmp > high){
                low = high;
                high = tmp;
                hp = i;
            } else if (tmp > low){
                low = tmp;
            }
        }

        printf("%d %d\n", hp, low);
    }

    return 0;
}

