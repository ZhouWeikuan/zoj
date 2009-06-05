#include<iostream>
using namespace std;
enum {
    SIZ = 204,
};
unsigned mask[SIZ][SIZ];
int num;
char buf[SIZ];

void parse(){
    memset(mask, 0, sizeof(mask));
    int a,b,i,t;
    scanf("%d%d",&a,&b);
    while(a + b){
        scanf("%s",buf);
        a--,b--;
        t = 0;
        for(i=0;buf[i];i++){
            t = buf[i] -'a';
            mask[a][b] |= (1<<t);
        }

        scanf("%d%d",&a,&b);
    }
    unsigned m;
    t = 1;
    while(t){
        t = 0;
        for(i=0;i<num;i++){
            for(a=0;a<num;a++){
                if(a==i)
                    continue;
                for(b=0;b<num;b++){
                    if(b==i || b ==a)
                        continue;
                    m = mask[a][i] & mask[i][b];
                    m |= mask[a][b];
                    if(mask[a][b] != m){
                        t = 1;
                        mask[a][b] = m;
                    }
                }
            }
        }
    }

}

int fun(){
    int a,b,i;
    unsigned m;
    scanf("%d%d",&a,&b);
    while(a+b){
        a --, b--;
        m = mask[a][b];
        if(m ==0){
            printf("-\n");
        } else {
            i = 0;
            while(m){
                if(m&0x01){
                    putchar('a' + i);
                }
                m>>=1;
                i++;
            }
            printf("\n");
        }
        scanf("%d%d",&a,&b);
    }

    return 0;
}

int main(){
    scanf("%d",&num);
    while(num){
        parse();
        fun();
        printf("\n");
        scanf("%d",&num);
    }

	return 0;
}
