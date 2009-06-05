#include<cstdio>

using namespace std;
enum {
    SIZ = 208,
};
char tri[SIZ][SIZ];
int  dis[SIZ][SIZ];
int  num, lim;
void readIn(){
    int i,j;
    lim = 2 * num - 1;
    for(i=0;i<num;i++){
        for(j=i;j<lim -i; j++){
            scanf(" %c ", &tri[i][j]);
        }
    }
    for(i=0;i<num;i++){
        dis[i][lim-i] = 0;
        for(j=lim-i-1;j>=i;j--){
            if(tri[i][j]  == '#'){
                dis[i][j] = 0;
            } else {
                dis[i][j] = dis[i][j+1] + 1;
            }
        }
    }
}
int expand_up(int a, int b){
    int ret = 1, t;
    int r = 0, c = b;
    r ++;
    while(a - r >= 0){
        c = b - r;
        if(c < a - r )
            break;
        t = 2 * r + 1;
        if(dis[a-r][c] >= t){
            ret += t;
        } else {
            break;
        }
        r ++;
    }
    return ret;
}
int expand_dn(int a, int b){
    int ret = 1, t;
    int r = 0, c;
    r ++;
    while(a + r < num){
        c = b - r;
        if(c < a + r)
            break;
        t = 2 * r + 1;
        if(dis[a+r][c] >= t){
            ret += t;
        } else {
            break;
        }
        r ++;
    }
    return ret;
}
int fun(){
    int ans = 0, t;
    int i,j;
    for(i=0; i<num; i++){
        for(j=i;j<lim - i;j++){
            if(tri[i][j] == '#')
                continue;
            if((j + i)%2==0){
                t = expand_up(i,j);
            } else {
                t = expand_dn(i,j);
            }
            if(t > ans)
                ans = t;
        }
    }
    return ans;
}
int main(){
    int tstcase = 0; 
    scanf("%d", &num);
    while(num){
        readIn();
        printf("Triangle #%d\n", ++tstcase);
        printf("The largest triangle area is %d.\n\n", fun());
        scanf("%d", &num);
    }
	return 0;
}
