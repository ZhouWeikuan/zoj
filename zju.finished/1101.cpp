#include<cstdio>
#include<cstdlib>

using namespace std;
enum {
    SIZ = 1004,
};
int num;
int wage[SIZ];

// small first;
int cmp(const int*a, const int*b){
    return *a - *b;
}

void readIn(){
    for(int i=0;i<num;i++){
        scanf("%d",&wage[i]);
    }
    qsort(wage, num, sizeof(int), 
            (int (*)(const void*, const void*))cmp);
}

int fun(){
    int ret = -1;
    int i,j,k;
    int s1,s2,s3;
    int *p;
    for(i=num-1;i>=0;i--){ // 注意 j + k + x = i时，i可能在min(j,k,x)和max(j,k,x)之间
        s1 = wage[i];
        for(j=num-1; j>=1;j--){
            if(j==i)
                continue;
            s2 = s1 - wage[j];
            for(k=j-1; k>=0; k--){
                if(k==i)
                    continue;
                s3 = s2 - wage[k];
                if(s3 < wage[0] || s3>wage[num-1])
                    continue;
                p = (int*)bsearch(&s3, wage, num, sizeof(int), 
                        (int (*)(const void*, const void*))cmp);
                if(p != NULL){
                    ret = p - wage;
                    if(ret != i && ret!=j && ret!=k)
                        return i;
                }
            }
        }
    }

    return -1;
}

int main(){
    int t;
    scanf("%d",&num);
    while(num > 0){
        readIn();
        t = fun();
        if(t >= 0){
            printf("%d\n", wage[t]);
        } else {
            printf("no solution\n");
        }
        scanf("%d",&num);
    }

	return 0;
}
