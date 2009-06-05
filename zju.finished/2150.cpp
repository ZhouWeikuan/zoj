#include<cstdio>

using namespace std;

int M;
int h;

//  a^b mod m ==
//  t = a^(b/2) mod m
//  t = t*t mod m
//  if b % 2 == 1 then
//      t = t*a mod m
//  fi
int modu(int a, int b){
    if(b == 1)
        return a%M;
    int t;
    t = modu(a, b/2);
    t *= t;
    t %= M;
    if(b % 2 == 1){
        t *= a;
        t %= M;
    }
    return t;
}

int fun(){
    int a,b;
    int ret = 0;
    while(h--){
        scanf("%d%d",&a,&b);
        a %= M;
        if(b == 0 || a == 1){
            ret += 1;
        } else if(a == 0){
            ret += 0;
        } else {
            ret += modu(a,b);
        }
    }

    return ret%M;
}

int main(){
    int tstcase;

    scanf("%d",&tstcase);
    while(tstcase --){
        scanf("%d%d",&M,&h);
        h = fun();
        printf("%d\n",h);

    }


	return 0;
}
