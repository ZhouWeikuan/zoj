#include<iostream>
#include<cmath>

using namespace std;
enum {
	Size = 1000001,
};
int save[Size] = {0};
int Lim = 1 + (int)sqrt((double)Size);

void init(){
	int i,j, t;
    
	for(i=2;i<Lim;i++){
        j = i * i;   // 特殊处理i * i == j的情况，防止i多加一次
        t = i + i;
        save[j] += i;
		for(j+=i,t ++;j<Size;j+=i,t++){
			save[j]+= t;
		}	
	}
    save[0] = -1;
    sort(save, save+Size);
}
int find(int v){
    int low = 0, high = Size, mid = (low + high)/2;
    while(low < high){
        if(save[mid] <= v){
            low = mid + 1;
        } else {
            high = mid;
        }
        mid = (low + high)/2;
    }

    return mid;
}

int main(){
	int n;
	init();
	while(scanf("%d",&n)>=0){
        n --;
        if(n < 0){
            printf("0\n");
        } else if(n >= save[Size-1]){
            printf("%d\n", Size -1);
        } else {
            n = find( n );
            n --;
            printf("%d\n", n);
        }
	}

	return 0;
}
