#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;
int move[6][3] = {
    {1, 0, 0}, {-1, 0, 0},
    {0, 1, 0}, {0, -1, 0},
    {0, 0, 1}, {0, 0, -1}
};
enum {
    SIZ = 12,
};
struct Node {
    int x,y,z;
};
int space[SIZ][SIZ][SIZ];
int num;
Node from, to;

void readIn(){
    int i,j,k,t;
    char ch;
    memset(space, 0, sizeof(space));
    // 注意此时的输入，从三，二，一维逆序输入
    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            for(k=0;k<num;k++){
                scanf("%c ",&ch);
                if(ch == 'O'){
                    t = -1;
                } else {
                    t = -2;
                }
                space[k][j][i] = t;
            }
        }
    }
    scanf("%d %d %d ", &from.x, &from.y, &from.z);
    scanf("%d %d %d ", &to.x, &to.y, &to.z);
}

int fun(){
    if(from.x == to.x && from.y == to.y && from.z == to.z)
        return 0;
    if(space[from.x][from.y][from.z] != -1 
            || space[to.x][to.y][to.z] != -1){
        return -1;
    }
    queue<Node> q;
    Node cur, one;
    q.push(from);
    space[from.x][from.y][from.z] = 0;
    while(!q.empty()){
        cur = q.front(); q.pop();
        int t = space[cur.x][cur.y][cur.z] ;
        for(int i=0;i<6;i++){
            one.x = cur.x + move[i][0];
            one.y = cur.y + move[i][1];
            one.z = cur.z + move[i][2];
            if(space[one.x][one.y][one.z] != -1)
                continue;
            if(one.x==to.x && one.y==to.y && one.z==to.z)
                return (t+1);
            space[one.x][one.y][one.z] = t + 1;
            q.push(one);
        }
    }
    return -1;
}

int main(){
    char buf[20];
    int t;
    scanf("%s",buf);
    while(strcmp(buf,"START")==0){
        scanf("%d ",&num);
        readIn();
        scanf("%s", buf);
        t = fun();
        if(t >= 0){
            printf("%d %d\n", num, t);
        } else {
            printf("NO ROUTE\n");
        }

        scanf("%s",buf);
    }

	return 0;
}
