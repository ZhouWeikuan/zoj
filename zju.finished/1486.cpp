#include<iostream>
using namespace std;
enum {
    SIZ = 100,
};
template<int N> 
struct BigNum {
	int d[N];
	int len;
	BigNum(){
		len = 0;
	}
	void operator=(int );
	void operator *=(int);
    void print();
};
template<int N>
void BigNum<N>::operator=(int n){
	len = 0;
	do {
		d[len++] = n%10;
		n /= 10;
	} while(n>0);
}
template<int N>
void BigNum<N>::operator *=(int m){
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
}
template<int N>
void BigNum<N>::print(void){
	for(int i=len-1;i>=0;i--){
		printf("%d", d[i]);
	}
    printf("\n");
}
int N, K;
BigNum<SIZ> res;

void fun(){
    res = K;
    for(int i=1; i<N; i++){
        res *= (K-1);
    }
    res.print();
}

int main(){
    int i, a, b;

    scanf("%d%d", &N, &K);
    while(N + K){
        for(i=1; i<N; i++){
            scanf("%d%d",&a,&b);
        }
        fun();
        scanf("%d%d", &N, &K);
    }
    return 0;
}

