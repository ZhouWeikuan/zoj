#include<iostream>
using namespace std;
enum {
    SIZ = 21,
};
template<int N> 
struct BigNum {
	int d[N];
	int len;
    bool pos;
	BigNum<N> & operator=(int );
	void operator +=(const BigNum<N> &);
	template<int O>
	friend ostream& operator<<(ostream& ,BigNum<O>&);
};
template<int N>
BigNum<N> & BigNum<N>::operator=(int n){
    if(n >= 0){
        pos = true;
    } else {
        pos = false;
    }
	len = 0;
	do {
		d[len++] = n%10;
		n /= 10;
	} while(n>0);
	return *this;
}

template<int N>
void BigNum<N>::operator +=( const BigNum<N> & rhs){
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
ostream& operator<<(ostream& o, BigNum<N>& rhs){
	for(int i=rhs.len-1;i>=0;i--){
		o<<rhs.d[i];
	}
	return o;
}

typedef BigNum<60> data_t;
int N,K;
data_t mat[2][SIZ][SIZ];

void readIn(){
    char t;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf(" %c ", &t);
            if(t == '0'){
                mat[0][i][j] = 0;
            } else {
                mat[0][i][j] = -1;
            }
        }
    }
}
void fun(){
    typedef data_t (*Ptr)[SIZ];
    Ptr pre, now, tmp;
    pre = mat[0], now = mat[1];
    pre[0][0] = 1;
    for(int s=0; s<K; s++){
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(pre[i][j].pos == false){
                    now[i][j].pos = false;
                    continue;
                }
                now[i][j] = 0;
                if(i>0 && pre[i-1][j].pos) 
                    now[i][j] += pre[i-1][j];
                if(j>0 && pre[i][j-1].pos) 
                    now[i][j] += pre[i][j-1];
                if(i<N-1 && pre[i+1][j].pos) 
                    now[i][j] += pre[i+1][j];
                if(j<N-1 && pre[i][j+1].pos) 
                    now[i][j] += pre[i][j+1];
            }
        }
        tmp = now;
        now = pre;
        pre = tmp;
    }
    cout<<pre[N-1][N-1]<<endl;
}
int main(){

    while( scanf("%d%d",&N,&K) > 0 ){
        readIn();
        fun();
    }

    return 0;
}

