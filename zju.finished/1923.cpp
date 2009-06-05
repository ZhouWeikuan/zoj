#include<iostream>
using namespace std;
template<int N> 
struct BigNum {
	int d[N];
	int len;
	BigNum(){
		len = 0;
	}
	BigNum(const char *);
	BigNum<N> & operator *=(int);
	BigNum<N> & operator /=(int);
	int operator %(int);
	template<int O>
	friend ostream& operator<<(ostream& ,BigNum<O>&);
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
BigNum<N> & BigNum<N>::operator /=(int dm){
	int carry = 0;
	int i;
	for(i=len-1;i>=0;i--){
		carry *= 10;
		carry += d[i];
		d[i] = carry / dm;
		carry = carry % dm;
	}
	while(d[--len] ==0){
		;
	}
	len ++;
	return *this;
}
template<int N>
int BigNum<N>::operator %(int dm){
	int carry = 0;
	int i;
	for(i=len-1;i>=0;i--){
		carry *= 10;
		carry += d[i];
		carry = carry % dm;
	}
	return carry;
}

template<int N>
ostream& operator<<(ostream& o, BigNum<N>& rhs){
	for(int i=rhs.len-1;i>=0;i--){
		o<<rhs.d[i];
	}
	return o;
}
enum {
    SIZ = 1008,
};
char buf[SIZ];
int st[SIZ], top;

void fun(){
    if(buf[1] == 0){
        cout<<1<<buf[0]<<endl;
        return;
    }
    top = 0;
    int t;
    BigNum<SIZ> b(buf);
    for(t=9;t>1;t--){
        while(b%t == 0){
            b /= t;
            st[top++] = t;
        }
    }
    if(b.len ==1 && b.d[0] == 1){
        for(t = top-1;t>=0;t--){
            cout<<st[t];
        }
        cout<<endl;
    } else {
        cout<<"There is no such number."<<endl;
    }
}

int main(){
    cin>>buf;
    while(buf[0] !='-'){
        fun();
        cin>>buf;
    }
    return 0;
}
