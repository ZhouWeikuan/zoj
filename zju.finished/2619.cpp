#include<iostream>
using namespace std;
template<int N> 
struct BigNum {
	int d[N];
	int len;
	BigNum(){
		len = 0;
	}
	BigNum<N> & operator = (int );
	BigNum<N> & operator *=(int);
	BigNum<N> & operator +=(int);
	template<int O>
	friend ostream& operator<<(ostream& ,BigNum<O>&);
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
BigNum<N> & BigNum<N>::operator +=(int carry){
    int i;
    for(i=0;i<len && carry;i++){
        carry += d[i];
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
ostream& operator<<(ostream& o, BigNum<N>& rhs){
	for(int i=rhs.len-1;i>=0;i--){
		o<<rhs.d[i];
	}
	return o;
}
int N;
char buf[20];

void fun(){
    cin>>N>>buf;
    int i;
    BigNum<40> res;

    res = 0;
    int len = strlen(buf);
    for(i=0;buf[i];i++){
        if( strncmp(&buf[i], &buf[0], len-i) == 0){
            res += 1;
        }
        res *= N;
    }
    cout<<res<<endl;
}

int main(){
    int tstcase = 0, tstnum;
    cin>>tstnum;
    while(tstcase ++ < tstnum){
        cout<<"Case "<<tstcase<<":"<<endl;
        fun();
        if(tstcase < tstnum)
            cout<<endl;
    }

    return 0;
}
