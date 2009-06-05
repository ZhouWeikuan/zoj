#include<iostream>
using namespace std;
enum {
    SIZ = 40,
};
int save[SIZ],top;
int num;

void calc(int s, int n){
    if(n ==0){
        if( top <= 1)
            return;
        printf("{%d", save[0]);
        for(int i=1;i<top;i++){
            printf(",%d", save[i]);
        }
        printf("}\n");
    } else if(n < s){
        return;
    }
    int lim = num / 2;
    for( ;s<=n && s<=lim;s++){
        save[top++] = s;
        calc(s, n - s);
        --top;
    }

}

int main(){

    scanf("%d",&num);
    while(num){
        num *= 2;
        
        calc(1, num);
        printf("\n");
        scanf("%d",&num);
    }

	return 0;
}
