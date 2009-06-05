#include<cstdio>

using namespace std;
enum {
	Size= 1001,
};
template<int N> 
struct BigNum {
	int d[N];
	int len;
	BigNum(){
		len = 0;
	}
	void operator +=(BigNum<N> &);
	void operator +=(int);
	void output();
};
template<int N>
void BigNum<N>::output(){
	if(len < 1){
		printf("0");
		return;
	}
	for(int i=len-1;i>=0;i--){
		printf("%d",d[i]);
	}
}
template<int N>
void BigNum<N>::operator+=(int r){
	int i = 0;
	d[i] += r;
	while(d[i] > 9){
		d[i+1] += d[i] /10; 
		d[i] %= 10;
		i++;
	}
	if(i > len || len < 1)
		len = i + 1;
}

template<int N>
void BigNum<N>::operator+=(BigNum<N> &rhs){
	int i = 0, carry=0;
	while(i<len && i < rhs.len){
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
	while(i<rhs.len){
		carry += rhs.d[i];
		d[i] = carry %10;
		carry /= 10;
		i++;
	}
	while(carry ){
		d[i] = carry %10;
		carry /= 10;
		i++;
	}
	len = i;
	if(len > N){
		printf("Error\n");
	}
}

struct Stat {
	BigNum<312> seq[4];  // 00->0, 01->1, 10->2, 11->3
};
Stat tree[Size];
void init(){
	tree[1].seq[1].len = 1;
	tree[1].seq[1].d[0] = 1;
	for(int i=2;i<Size;i++){
		// 00-> 1010
		tree[i].seq[2] += tree[i-1].seq[0];
		tree[i].seq[1] += tree[i-1].seq[0];
		// 01-> 1001
		tree[i].seq[2] += tree[i-1].seq[1];
		tree[i].seq[0] += tree[i-1].seq[1];
		// 10-> 0110
		tree[i].seq[1] += tree[i-1].seq[2];
		tree[i].seq[3] += tree[i-1].seq[2];
		// 11-> 0101
		tree[i].seq[1] += tree[i-1].seq[3];
		tree[i].seq[2] += tree[i-1].seq[3];

		// 1 -> 01
		tree[i].seq[1] += 1;
	}
}

int main(){
	int n;
	init();
	while( scanf("%d",&n) >= 0){
		tree[n].seq[0].output();
		printf("\n");
	}

	return 0;
}
