#include<iostream>
#include<vector>
using namespace std;
enum {
    SIZ = 54,
};
int N, M;
int dat[SIZ];
vector<int> v;

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

int lcm(int a, int b){
    int t = gcd(a, b);
    a *= b;
    a /= t;
    return a;
}

void fun(){
    unsigned H, L, tab, s;
    int i,j;
    for (i=0; i<M; ++i){
        scanf("%d", &tab);
        H = -1, L = 0;
        for (j=0; j<v.size(); ++j){
            s = tab / v[j] * v[j];
            if (s > L){
                L = s;
            }
            if (s != tab)
                s += v[j];
            if (s < H){
                H = s;
            }
        }
        printf("%d %d\n", L, H);
    }
}

int readIn(){
    scanf("%d%d", &N, &M);
    if (N == 0 && M == 0) return 0;
    int i,j,k,l;
    v.clear();
    for (i=0; i<N; ++i)
        scanf("%d", &dat[i]);
    for (i=0; i<N; ++i){
        for (j=i+1; j<N; ++j){
            for (k=j+1; k<N; ++k){
                for (l=k+1; l<N; ++l){
                    v.push_back(lcm(lcm(lcm(dat[i],dat[j]),dat[k]),dat[l]));
                }
            }
        }
    }
    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

