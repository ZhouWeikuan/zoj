#include<iostream>
using namespace std;

int deg;

void fun(){
    deg = 360 - deg;
    int a = ((deg / 30) + 3)%12;
    if (deg % 30 == 0){
        printf("Exactly %d o'clock\n", a);
    } else {
        int b = (a + 1)%12;
        printf("Between %d o'clock and %d o'clock\n", a, b);
    }
}

int main(){

    scanf("%d", &deg);
    while(deg >= 0){
        fun();
        scanf("%d", &deg);
    }

    return 0;
}

