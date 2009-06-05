#include<iostream>
using namespace std;
enum {
    SIZ = 55,
};
template<int N> 
struct BigNum {
	int d[N];
	int len;
	BigNum(){
		len = 0;
	}
	BigNum(const char *);
	BigNum<N> & operator=(const BigNum<N> & );
	BigNum<N> & operator *=(int);
	BigNum<N> & operator +=(const BigNum<N> &);
	template<int O>
	friend ostream& operator<<(ostream& ,const BigNum<O>&);
};
template<int N>
BigNum<N>::BigNum(const char *s){
	len = strlen(s);
	int t = len;
	while(t){
		d[len -t] = s[t-1] -'0';
		t --;
	}
}
template<int N>
BigNum<N> & BigNum<N>::operator=(const BigNum<N> & rhs){
	len = rhs.len;
	for(int i=0;i<len;i++){
		d[i] = rhs.d[i];
	}
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
ostream& operator<<(ostream& o, const BigNum<N>& rhs){
	for(int i=rhs.len-1;i>=0;i--){
		o<<rhs.d[i];
	}
	return o;
}
BigNum<100> s[SIZ][SIZ];
int num;

void init(){
    BigNum<100> v;
    int i,j;
    s[0][0] = "1";
    s[1][0] = "1";
    s[1][1] = "1";
    for(i=2; i<SIZ; i++){
        v = "2";
        s[i][1] = "1";
        s[i][i] = "1";
        for(j=2;j<i;j++){
            s[i][j] = s[i-1][j];
            s[i][j] *= j;
            s[i][j] += s[i-1][j-1];
            v += s[i][j];
        }
        s[i][0] = v;
    }
}

int main(){
    init();

    scanf("%d",&num);
    while( num ){
        cout<<num<<" "<< s[num][0]<<endl;
        scanf("%d",&num);
    }
    return 0;
}

