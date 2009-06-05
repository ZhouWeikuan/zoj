#include<cstdio>
#include<map>

using namespace std;
enum {
    SIZ = 4100,
};
int mark[SIZ];
int val;

int fun(){
    int num, pos;
    int i,t;
    memset(mark, 0, sizeof(mark));
    val = 0;

    scanf("%d", &num);
    while(num --){
        scanf("%d", &pos);
        if(mark[pos] == 0){
            mark[pos] = 1;
        } else {
            mark[pos] = 0;
        }
        t = 0;
        for(i=pos;i<SIZ;i++){
            if(mark[i] ==0)
                break;
            t ++;
        }
        for(i=pos-1;i>=0; i--){
            if(mark[i] == 0)
                break;
            t ++;
        }
        if(t > val)
            val = t;
    }
    return val;
}

int main(){
    int tstcase ;

    scanf("%d", &tstcase);
    while(tstcase --){
        printf("%d\n", fun());
    }

	return 0;
}

