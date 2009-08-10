#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 104,
    LIM = 1234567890,
};

long long N, K;

long long fun(){
    long long r = 0;
    if (K == 0){
        return (N-1)>LIM?(LIM+1):(N-1);
    } else if (K == 1){
        r = (N-1)*N/2;
        if (r > LIM){
            r = 1234572895ll;
        }
        return r;
    }
    long long sum = 1, s = 1;
    deque<long long> q;
    q.push_back(1);
    while(N-- > 1 && r <= LIM){
        if (q.size() > K){
            s -= q.front();
            q.pop_front();
        }
        r += sum;
        q.push_back(s);
        sum += s;
        // printf("adding %lld, %lld, %lld\n", s, sum, r);
        s += s;
    }
    return r;
}

int main(){

    scanf("%lld%lld", &N, &K);
    while(N > 0){
        K = fun();
        printf("%lld\n", K);
        scanf("%lld%lld", &N, &K);
    }

    return 0;
}

