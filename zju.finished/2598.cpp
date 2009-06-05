
#include<iostream>
using namespace std;
enum {
    SIZ = 2008,
};
// 从前往后推110101等串，判断为0为1时的递推关系
template<int N>
struct BigNum {
    int d[N];
    int len;
    BigNum(){
        len = 0;
    }
    void operator = (const char *);
    int  operator %=(int);
    void operator *=(int);
    void operator = (int);
    void operator = (const BigNum<N> &rhs);
    void operator += (const BigNum<N> &rhs);
    inline bool zero(){
        return len==0||(len==1&&d[0]==0);
    }
    template<int O>
    friend ostream& operator<<(ostream& ,BigNum<O>&);
};
template<int N>
ostream& operator<<(ostream& o, BigNum<N>& rhs){
    for(int i=rhs.len-1;i>=0;i--){
        o<<rhs.d[i];
    }
    return o;
}
template<int N>
void BigNum<N>::operator =(const char *s){
    len = strlen(s);
    int t = len;
    while(t){
        d[len -t] = s[t-1] -'0';
        t --;
    }
}
template<int N>
void BigNum<N>::operator =(int v){
    len = 0;
    if(v == 0){
        d[len++] = 0;
    }
    while(v > 0){
        d[len++] = v % 10;
        v /= 10;
    }
}
template<int N>
void BigNum<N>::operator *=(int m){
    int carry = 0, i;
    for(i=0;i<len;i++){
        carry += d[i] * m;
        d[i] = carry % 10;
        carry /= 10;
    }
    while(carry){
        d[len++] = carry % 10;
        carry /= 10;
    }
}

template<int N>
int BigNum<N>::operator %=(int dm){
    int carry = 0;
    int i;
    for(i=len-1;i>=0;i--){
        carry *= 10;
        carry += d[i];
        d[i]   = carry / dm;
        carry %= dm;
    }
    while(len > 0 && d[len-1] ==0){
        len--;
    }
    return carry;
}
template<int N>
void BigNum<N>::operator = (const BigNum<N> &rhs){
    for(len = 0; len<rhs.len;len++){
        d[len] = rhs.d[len];
    }
}

template<int N>
void BigNum<N>::operator += (const BigNum<N> &rhs){
    int i = 0, carry = 0;
    while(i < len && i < rhs.len){
        carry += d[i] + rhs.d[i];
        d[i] = carry % 10;
        carry /= 10;
        i++;
    }
    while(i < len){
        carry += d[i];
        d[i] = carry % 10;
        carry /= 10;
        i++;
    }
    while(i < rhs.len){
        carry += rhs.d[i];
        d[i] = carry % 10;
        carry /= 10;
        i++;
    }
    while(carry){
        d[i++] = carry % 10;
        carry /= 10;
    }
    len = i;
}

struct Node {
    BigNum<SIZ> a[3];
    BigNum<SIZ> two;
    int len1;
};

BigNum<SIZ> R;
char input[SIZ];
int dat[SIZ], pos;
Node tab[2];

void trans(){
    pos = 0;
    while(!R.zero()){
        dat[pos++] = (R%=2);
    }
}
void fun(){
    Node *pre=&tab[0],*cur=&tab[1], *tmp;
    pre->a[0] = 0;
    pre->a[1] = 1;
    pre->a[2] = 0;
    pre->two  = 0;
    pre->len1 = 1;
    for(int i=pos-2;i>=0;i--){
        if(dat[i] == 0){
            cur->a[0] = 0;
            cur->a[0] += pre->a[0];
            cur->a[0] += pre->a[1];
            cur->a[0] += pre->a[2];
            cur->two = 0;
            cur->a[1] = 0;
            cur->a[2] = pre->a[1];
            cur->a[2] *= pre->len1;
            cur->a[2] += pre->two;
            cur->a[2] += pre->a[2];
            cur->len1 = 0;
        } else if(dat[i] == dat[i+1]){ // consective 1.
            cur->a[0] = pre->a[0];
            cur->a[1] = pre->a[1];
            cur->a[2] = pre->a[2];
            cur->two  = pre->two;
            cur->len1 = pre->len1 + 1;
        } else {
            cur->a[0] = 0;
            cur->len1 = 1;
            cur->a[1] = pre->a[0];
            cur->a[1] += pre->a[1];
            cur->a[1] += pre->a[2];
            cur->a[2] = 0;
            cur->two = pre->a[2];
        }
        tmp = cur; cur = pre; pre=tmp;
    }
    R = 0;
    R += pre->a[0];
    R += pre->a[1];
    R += pre->a[2];
    cout<<R<<endl;
}

int main(){
    while( scanf("%s", input) > 0 && input[0] !='-') {
        R = (input);
        trans();
        fun();
    }

    return 0;
}
