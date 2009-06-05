#include<cstdio>
//相当于移位再同余
using namespace std;
enum {
    SIZ = 61200,
};
int tree[SIZ];
int N, start;

void readIn(){
    for(int i=0;i<N;i++){
        scanf("%d ", &tree[i]);
    }
}

int fun(){
    start = 0;
    for(int i=0;i<N;i++){
        start += tree[start];
        start %= N;
    }
    return tree[start];
}

int main(){
    
    while( scanf("%d ", &N) > 0){
        readIn();
        printf("%d\n", fun());
    }

	return 0;
}
