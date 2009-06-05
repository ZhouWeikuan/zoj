#include<iostream>
using namespace std;
enum {
    SIZ = 1008,
    LEN = 84,
};
struct Node {
    int     num;
    double  val;
    char    name[LEN];
};
Node best, cur;
char buf[LEN];

void fun(){
}

int main(){
    int tstcase = 0;
    int a, b;
    scanf("%d%d ",&a,&b);
    while(a){
        if(tstcase){
            printf("\n");
        }
        while(a--){
            fgets(buf, LEN, stdin);
        }
        fgets(best.name, LEN, stdin);
        scanf(" %lf%d ",&best.val, &best.num );
        for(int j=0;j<best.num;j++){
            fgets(buf, LEN, stdin);
        }
        for(int i=1; i<b; i++){
            fgets(cur.name, LEN, stdin);
            scanf(" %lf%d ",&cur.val, &cur.num );
            for(int j=0;j<cur.num;j++){
                fgets(buf, LEN, stdin);
            }
            if(cur.num > best.num ||(cur.num==best.num&&cur.val<best.val)){
                best = cur;
            }
        }
        printf("RFP #%d\n", ++tstcase);
        printf("%s", best.name);

        scanf("%d%d ",&a,&b);
    }
    return 0;
}

