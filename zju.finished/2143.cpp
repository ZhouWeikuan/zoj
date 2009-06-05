#include<iostream>
using namespace std;
enum {
    SIZ = 200,
};

template<int N> 
struct BigNum {
	int d[N];
	int len;
	BigNum(){
		len = 0;
	}
	BigNum<N> & operator=(const char *);
	int operator %=(int);
};
template<int N>
BigNum<N> & BigNum<N>::operator=(const char *s){
	len = strlen(s);
	int t = len;
	while(t){
		d[len -t] = s[t-1] -'0';
		t --;
	}
}

template<int N>
int BigNum<N>::operator %=(int dm){
	int carry = 0;
	int i;
	for(i=len-1;i>=0;i--){
		carry *= 10;
		carry += d[i];
		d[i] = carry / dm;
		carry = carry % dm;
	}
	while(len > 0 && d[len-1] ==0){
		len--;
	}
	return carry;
}

int base;
char sym[SIZ];
char buf[SIZ];
BigNum<SIZ> orig, res;

void fun(){
    res.len = 0;
    while(orig.len>0 || orig.d[0]!=0){
        res.d[res.len++] = (orig %= base);
    }
    int half = base / 2, i;
    for(i=0; i<res.len; i++){
        if(i == res.len -1){
            res.d[res.len] = 0;
        }
        while(res.d[i] > half){
            res.d[i] -= base;
            res.d[i+1] += 1;
            if(i==res.len-1){
                res.len++;
            }
        } 
        /*
        while(res.d[i] < -half){
            res.d[i] += base;
            res.d[i+1]--;
            if(i==res.len-1){
                res.len++;
            }
        }*/
    }
    for(i=res.len-1; i>=0; i--){
        if(res.d[i] >= 0){
            printf("%c", sym[res.d[i]]);
        } else {
            printf("-%c", sym[-res.d[i]]);
        }
    }
    printf("\n");
}
void readIn(){
    scanf("%d %s ", &base, buf);
    orig = buf;
}
void init(){
    int i, t=0;
    for(i=0; i<10; i++){
        sym[t++] = '0' + i;
    }
    for(i=0; i<26; i++){
        sym[t++] = 'A' + i;
    }
    for(i=0; i<26; i++){
        sym[t++] = 'a' + i;
    }
}
int main(){
    int tst;
    init();
    scanf("%d ", &tst);
    while(tst--){
        readIn();
        fun();
    }

    return 0;
}

