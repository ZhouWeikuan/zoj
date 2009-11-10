#include<stdio.h>

typedef long long ulong;
ulong stair[520];
ulong heap[520][520];

void init(){
    int i;
    memset(heap,-1ll,sizeof(ulong)*520*520);
    for(i=0;i<520;i++)
        heap[i][0] = 0ll;
    heap[0][0] = 1ll;
}

ulong calc(int n,int k){    
    ulong t = 0ll;
 
	if(k > n) {
        k = n;         
    }   
    if(heap[n][k] >= 0ll)
        return heap[n][k];
    if(n <=2){
        if(k >= n)
            heap[n][k] = 1ll;
        else
            heap[n][k] = 0ll;
        return heap[n][k];
    }   
    
    int i;
    int lim;
    for(i=k;i*(i+1)/2 >= n;i--){
        lim = i -1;        
		if(lim > n-i)
			lim = n-i;
        t += calc(n-i,lim);
    }
    heap[n][k] = t;
	return t;
}

void fun(int n){    
    if(stair[n]){
        return;
    }
    if(n < 3)
        return;
    ulong t =0ll;
    int i = n-1;
    int lim;
	while(i>n-i){
		fun(n-i);
		t += stair[n-i] + 1ll;
		i--;
	}	
	for(; (i+1)*i/2 >= n;i--){
        lim = i -1;
        lim = lim <=(n-i)? lim :(n-i);        
        calc(n-i,lim);
		t += heap[n-i][lim];
    }
    stair[n] = t;
}


int main(){
    int num;
    init();
    
    scanf("%d",&num);
    while(num){
        fun(num);
        printf("%lld\n",stair[num]);
        scanf("%d",&num);
    }
    return 0;
}
