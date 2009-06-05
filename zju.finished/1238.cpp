#include<iostream>
#include<cmath>
using namespace std;
template<int N> 
struct BigNum {
	int d[N];
	int len;
    BigNum():len(0){}
	void set(const char *);
	int operator /=(int);
};
template<int N>
void BigNum<N>::set(const char *s){
	len = strlen(s);
	int t = len;
	while(t){
		d[len -t] = s[t-1] -'0';
		t --;
	}
}
template<int N>
int BigNum<N>::operator /=(int dm){
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
	return carry;
}

enum {
    SIZ = 500008,
};

BigNum<SIZ> n;
char buf[SIZ];
int len;
const int arr[4] = {
    0, 1, 4, 27
};

int find(){
    int low = 1, high= SIZ, mid;
    int p;
    mid = (low + high)/2;
    while(low < high){
        p = int(mid * log10((double)mid)) + 1;
        if(p < len){
            low = mid + 1;
        } else if(p > len){
            high = mid;
        } else {
            break;
        }
        mid = (low + high)/2;
    }
    p = int(mid * log10((double)mid)) + 1;
    if(p != len)
        return -1;
    return mid;
}

void fun(){
    int pos = find();
    if(pos == -1){
        printf("-1\n");
        return;
    }
    n.set(buf);
    int val = pos;
    int t;
    t = (n /= val);
    if(t!=0){
        printf("-1\n");
    } else {
        printf("%d\n", val);
    }
}

int main(){
    int tstcase;
    scanf("%d", &tstcase);
    while(tstcase --){
        scanf("%s", buf);
        len = strlen(buf);
        if(len <= 2){
            int t = atoi(buf),i;
            for(i=1;i<4;i++){
                if(arr[i] == t){
                    break;
                }
            }
            if(i == 4){
                printf("-1\n");
            } else {
                printf("%d\n",i);
            }
        }else {
            fun();
        }
    }
}
