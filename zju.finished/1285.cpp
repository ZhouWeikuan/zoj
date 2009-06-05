#include<iostream>
#include<string>
#include<map>
using namespace std;
enum {
    SIZ = 32,
};
int num, con, req;
unsigned dis[SIZ][SIZ];
map<string, int> ship;
char buf[10];
string s;

void fun(){
    int cnt,a,b,i;
    for(i=0; i<num; i++){
        for(a=0; a<num; a++){
            if(dis[a][i]==-1u) continue;
            for(b=0; b<num; b++){
                if(b==a||dis[i][b]==-1u) continue;
                if(dis[a][b] > dis[a][i] + dis[i][b]){
                    dis[a][b] = dis[a][i] + dis[i][b];
                }
            }
        }
    }
    printf("\n");
    while(req--){
        scanf("%d",&cnt);
        scanf("%s", buf); s = buf; a = ship[s];
        scanf("%s", buf); s = buf; b = ship[s];
        if(dis[a][b] == -1u){
            printf("NO SHIPMENT POSSIBLE\n");
        } else {
            cnt *= dis[a][b];
            cnt *= 100;
            printf("$%d\n", cnt);
        }
    }
}
void readIn(){
    int i,a,b;
    scanf("%d%d%d",&num, &con, &req);
    ship.clear();
    memset(dis, -1, sizeof(dis));
    for(i=0; i<num; i++){
        scanf("%s", buf);
        s = buf;
        ship.insert(make_pair(s, i));
    }
    for(i=0; i<con; i++){
        scanf("%s", buf);
        s = buf;
        a = ship[s];
        scanf("%s", buf);
        s = buf;
        b = ship[s];
        dis[a][b] = dis[b][a] = 1;
    }
}
int main(){
    int tst = 1, tstnum;

    printf("SHIPPING ROUTES OUTPUT\n\n");
    scanf("%d", &tstnum);
    while(tstnum--){
        readIn();
        printf("DATA SET %d\n", tst++);
        fun();
        printf("\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}

