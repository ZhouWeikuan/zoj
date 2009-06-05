#include<iostream>

using namespace std;
enum {
    SIZ = 100008,
};
int perm[SIZ], num;
// 1 ambiguous, 0, not
int fun(){
    int i;
    for(i=1;i<= num;i++){
        scanf("%d", &perm[i]);
    }
    for(i=1;i<=num;i++){
        if( perm[perm[i]] != i){
            return 0;
        }
    }
    return 1;
}

int main(){
    const char *ans[2] = {
        "not ",
        ""
    };
    int t;
    
    scanf("%d", &num);
    while(num ){
        t = fun();
        printf("%sambiguous\n", ans[t]);
        scanf("%d", &num);
    }

	return 0;
}
