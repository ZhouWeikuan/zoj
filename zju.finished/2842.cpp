#include<iostream>
using namespace std;
enum {
    SIZ = 26,
};
template<int N> 
struct BigNum {
	int d[N];
	int len;
	BigNum(){
		len = 0;
	}
	BigNum<N> & operator=(int );
	BigNum<N> & operator *=(int);
	BigNum<N> & operator +=(const BigNum<N> &);
    void print();
};
template<int N>
BigNum<N> & BigNum<N>::operator=(int n){
	len = 0;
	do {
		d[len++] = n%10;
		n /= 10;
	} while(n>0);
	return *this;
}

template<int N>
BigNum<N> & BigNum<N>::operator +=( const BigNum<N> & rhs){
    int i, carry = 0;
    for(i=0; i<len&&i<rhs.len; i++){
        carry += d[i] + rhs.d[i];
        d[i] = carry % 10;
        carry /= 10;
    }
    while(i<len){
        carry += d[i];
        d[i] = carry % 10;
        carry /= 10;
        i++;
    }
    while(i<rhs.len){
        carry += rhs.d[i];
        d[i] = carry % 10;
        carry /= 10;
        i++;
    }
    while(carry){
        d[i] = carry % 10;
        carry /= 10;
        i++;
    }
    len = i;
}

template<int N>
BigNum<N> & BigNum<N>::operator *=(int m){
	int carry = 0;
	int i;
	for(i=0;i<len;i++){
		carry += d[i] * m;
		d[i] = carry % 10;
		carry /= 10;
	}
	while(carry){
		d[len++] = carry % 10;
		carry /= 10;
	}
	return *this;
}

template<int N>
void BigNum<N>::print(void){
	for(int i=len-1;i>=0;i--){
		printf("%d",d[i]);
	}
    printf("\n");
}

int num;
char buf[SIZ+2];
bool use[SIZ];

void fun(){
    memset(use, false, sizeof(use));
    BigNum<100> ret, t;
    ret = 0;
    int s = 0, i;
    for(int p=0; p<num; p++){
        buf[p] -= 'A';
        use[buf[p]] = true;
        s=0;
        for(i=0; i<buf[p]; i++){
            s+=(use[i]==false);
        }
        t = s;
        for(i=p+1; i<num; i++){
            t *= (SIZ - i);
        }
        ret += t;
    }
    ret.print();
}
int readIn(){
    scanf("%d",&num);
    if(num == 0) return 0;
    scanf("%s", buf);
    return num;
}
int main(){
    while(readIn() > 0){
        fun();
    }
    return 0;
}

