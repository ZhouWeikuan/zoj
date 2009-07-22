#include<iostream>
using namespace std;
enum {
    SIZ = 104,
};
struct Node {
    unsigned long long up, dn;
    bool operator < (const Node&o)const{
        return dn < o.dn;
    }
    void add(const Node &o);
};

int gcd(unsigned long long a, unsigned long long b){
    unsigned long long t;
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

void Node::add(const Node &o) {
    if (o.up <= 0) return;
    if (up <= 0){
        up = o.up;
        dn = o.dn;
        return;
    }
    if (dn == o.dn){
        up += o.up;
    } else {
        unsigned long long t = gcd(dn, o.dn);
        t = dn * o.dn / t;
        up = t/dn*up + t/o.dn*o.up;
        dn = t;
        t = gcd(dn, up);
        dn /= t;
        up /= t;
    }
}

int num;
Node tre[SIZ];
Node sum[SIZ];

void fun(){
    if (sum[num-1].up > sum[num-1].dn){
        printf("-1\n");
        return;
    }
    unsigned long long r = 0;
    unsigned long long carry = 0;
    for (int i=num-1; i>0; --i){
        carry += tre[i].up;
        // u, stand for available ones each cycle
        unsigned long long u = tre[i-1].dn * (sum[i-1].dn - sum[i-1].up) / sum[i-1].dn;
        unsigned long long t = carry / u;
        r += t * tre[i-1].dn;
        carry %= u;
        if (carry ==0){
            break;
        }
    }
    if (carry){
        r += carry + tre[0].up;
    }
    if (num == 1)
        r = tre[0].up;
    printf("%llu\n", r);
}

void readIn(){
    scanf("%d ", &num);
    for (int i=0; i<num; ++i){
        scanf("%llu%llu ", &tre[i].up, &tre[i].dn);
    }
    sort(tre, tre+num);
    for (int i=0; i<num; ++i){
        sum[i].up = sum[i].dn = 0;
        sum[i].add(tre[i]);
        if (i){
            sum[i].add (sum[i-1]);
        }
    }
}

int main(){
    int tst;
    scanf("%d ", &tst);
    while(tst--){
        readIn();
        fun();
    }

    return 0;
}

