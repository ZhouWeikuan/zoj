#include<iostream>
using namespace std;
enum {
    SIZ = 6,
};
struct Triangle{
    int v[3];
    bool use;
};
int sum, e;
Triangle tri[SIZ];
void dfs(int d, int m, int s){
    if(d >= 6){
        if(m == e && s > sum)
            sum = s;
        return;
    }
    int i,j;
    for(i=0; i<SIZ; i++){
        if(tri[i].use) continue;
        for(j=0; j<3; j++){
            if(tri[i].v[j] == m){
                tri[i].use = true;
                dfs(d+1, tri[i].v[(j+2)%3], s + tri[i].v[(j+1)%3]);
                tri[i].use = false;
            }
        }
    }
}
void fun(){
    sum = 0;
    int i;
    for(i=0; i<3; i++){
        tri[0].use = true;
        e = tri[0].v[(i+1)%3];
        dfs(1, tri[0].v[i], tri[0].v[(i+2)%3]);
    }
    if(sum == 0){
        printf("none\n");
    } else {
        printf("%d\n", sum);
    }
}

void readIn(){
    int i,j;
    for(i=0; i<SIZ; i++){
        for(j=0; j<3; j++){
            scanf("%d", &tri[i].v[j]);
        }
    }
}
int main(){
    char ch;
    do {
        readIn();
        fun();
        scanf(" %c", &ch);
    } while(ch != '$');
    return 0;
}

