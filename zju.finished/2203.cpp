#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;
enum {
    SIZ = 1004,
};
int mask[SIZ];
int data[SIZ];
int from, to, num, top, lim;
int p[SIZ * 10] = {0};

void init_primes(){
	int flag ;
    int primes[SIZ * 4] = { 2, 3};
    int pnum = 2;
    int i = 3;
    int n = SIZ * 10;
	for(i+=2; i<n ;i +=2){
		int lim = (int)sqrt((double)i)+1;
		flag = 1;
		for(int j=0;primes[j]<lim;j++){
			if(i%primes[j]==0){
			    flag = 0;
				break;
			}
		}
		if(flag){
			primes[pnum++] = i;
		}
	}
    for(i=0;i<pnum;i++){
        p[primes[i]] = 1;
    }
}


int search(){
    if(top >= lim)
        return 1;
    int i, flag, s,j;
    for(i=from;i <=to ;i++){
        if(mask[i] == 1)
            continue;
        mask[i] = 1;
        data[top] = i;
        flag = 1;
        s = i;
        for(j=top-1;j>top-num&&j>=0 ;j--){
            s += data[j];
            if(p[s]){
                flag = 0;
                break;
            }
        }
        top ++;
        if(flag && search()){
            return 1;
        }
        top --;
        mask[i] = 0;
    }
    return 0;
}

void fun(){
    top = 0;
    lim = to - from + 1;
    memset(mask, 0, sizeof(mask));
    memset(data, 0, sizeof(data));
    if(search() == 0){
        printf("No anti-prime sequence exists.\n");
        return;
    }
    printf("%d", data[0]);
    for(int i=1;i<top;i++){
        printf(",%d", data[i]);
    } 
    printf("\n");
}

int main(){
    init_primes();
    
    scanf("%d%d%d",&from,&to,&num);
    while(from + to + num){
        fun();
        scanf("%d%d%d",&from,&to,&num);
    }

	return 0;
}
