#include<cstdio>
#include<cstring>
using namespace std;
/// 先求周期，再计算
enum {
    SIZ = 1004,
};

int S, x, y, dx, dy;

int gcd(int a, int b){
    int t;
    if( a < b){
        t = a, a = b, b = t;
    }
    while(b > 0){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

bool in_range()
{
    if (x == 0 || y == 0)
        return true;
    if ( x<=S && y<=S)
        return true;
    if ( x>=S && y>=S)
        return true;

    return false;
}

void fun(){
    int cnt = 0;
    int S2 = S * 2;
    int ox = x, oy = y;
    int cycle = (S2/gcd(S2, dx)) * (S2/gcd(S2, dy));

    for (int i=0;i<cycle;i++, cnt++)
    {
        x %= S2;
        y %= S2;
        if (!in_range())
            break;

        x = (x + dx) % S2;
        y = (y + dy) % S2;
    }

    if (cnt >= cycle) {
        printf("The flea cannot escape from black squares.\n");
    }
    else {
        x = ox + dx * cnt;
        y = oy + dy * cnt;
        printf("After %d jumps the flea lands at (%d, %d).\n", cnt, x, y);
    }
}

int readIn(){
    scanf("%d%d%d%d%d ", &S, &x, &y, &dx, &dy);
    return (S + x + y + dx + dy);
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

