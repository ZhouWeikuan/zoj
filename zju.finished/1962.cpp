#include<iostream>
#include<cstring>

using namespace std;
template<int N> 
struct BigNum {
	int d[N];
	int len;
	BigNum(){
		len = 0;
	}
	BigNum(const char *);
	void add(BigNum<N> & );
	int cmp(BigNum<N> &);
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
void BigNum<N>::add(BigNum<N> &rhs){
	int carry = 0;
	int i = 0;
	while(i < len && i < rhs.len){
		carry += d[i] + rhs.d[i];
		d[i] = carry %10;
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
		d[i] = carry % 10;
		carry /= 10;
		i ++;
	}
	len = i;
}

template<int N>
int BigNum<N>::cmp(BigNum<N> &rhs){
	if(len != rhs.len)
		return len - rhs.len;
	for(int i= len-1;i>=0;i--){
		if(d[i] != rhs.d[i])
			return d[i] - rhs.d[i];
	}
	return 0;
}
enum {
	Size = 102,
};
char buf[Size];
BigNum<Size> save[500];
int pos;

void init(){
	save[0].d[0] = 1; save[0].len = 1;
	save[1].d[0] = 2; save[1].len = 1;
	pos = 1;
	while(save[pos ++].len <= 100){
		save[pos].add(save[pos-1]);
		save[pos].add(save[pos-2]);
	}
}

int find(BigNum<Size> &obj){
	int high = pos-1, low = 0;
	int mid,t;
	while(low <= high){
		mid = (low+high)/2;
		t = obj.cmp(save[mid]);
		if(t ==0)
			return mid;
		else if(t > 0){
			low = mid + 1;
		} else {
			high = mid -1;
		}
	}
	return mid;
}

int le(BigNum<Size> &obj){
	int s = find(obj);
	int t = save[s].cmp(obj);
	if(t >= 0)
		return s;
	else 
		return s+1;
}
int gt(BigNum<Size> &obj){
	int s = find(obj);
	int t = save[s].cmp(obj);
	if(t >0)
		return s;
	else 
		return s+1;
}

int main(){
	int s,e;

	init();
	cin>>buf;
	BigNum<Size> a(buf);
	s = le(a);
	cin>>buf;
	while(buf[0]!='0' || buf[1] !=0){
		BigNum<Size> b(buf);
		e = gt(b);
		cout<<e-s<<endl;
		cin>>buf;
		BigNum<Size> a(buf);
		s = le(a);
		cin>>buf;
	}


	return 0;
}
