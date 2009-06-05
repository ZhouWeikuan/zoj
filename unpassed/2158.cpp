#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 2008,
    LEN = 8,
};
char truck[SIZ][LEN];
bool use[SIZ];
int cnt[7][26];
int num;

void readIn(){
    memset(cnt, 0, sizeof(cnt));
    memset(use, false, sizeof(use));
    int i,j;
    for(i=0; i<num; i++){
        scanf("%s", truck[i]);
        for(j=0;j<7;j++){
            truck[i][j] -= 'a';
        }
    }
    use[0] = true;
    for(j=0; j<7; j++){
        cnt[j][truck[0][j]] = 1;
    }
}
int getDis(int p){
    int ret = 0;
    for(int i=0; i<7; i++){
        ret += cnt[i][truck[p][i]]==0;
    }
    return ret;
}
void fun(){
    int ret = 0;
    int i,j, val, leaf = num - 1;
    int ptr;
    while(leaf > 0){
        val = 10;
        ptr = -1;
        for(i=0; i<num; i++){
            if(use[i]) continue;
            j = getDis(i);
            if(j < val){
                val = j;
                ptr = i;
            }
        }
        ret += val;
        leaf--; 
        use[ptr] = true;
        for(j=0; j<7; j++){
            cnt[j][truck[ptr][j]] = 1;
        }
    }
    printf("The highest possible quality is 1/%d.\n", ret);
}
int main(){
    scanf("%d", &num);
    while(num){
        readIn();
        fun();
        scanf("%d", &num);
    }
    return 0;
}

