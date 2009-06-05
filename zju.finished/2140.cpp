
#include<iostream>
#include<queue>
using namespace std;
enum {
    SIZ = 108,
};
int mat[SIZ][SIZ];
int ball[SIZ], num;
int ptr[SIZ], pos;
struct cmp{
    bool operator() (const int a, const int b) const {
        return ball[a] < ball[b];
    }
};
int readIn(){
    scanf("%d",&num);
    for(int i=0; i<num; i++){
        scanf("%d",&ball[i]);
    }
    return num;
}
bool fun(){
    memset(mat, 0, sizeof(mat));
    priority_queue<int, vector<int>, cmp> q;
    int i, cur, t;
    for(i=0; i<num; i++){
        if(ball[i] >= num) 
            return false;
        if(ball[i] > 0)
            q.push(i);
    }
    while(!q.empty()){
        cur = q.top(); q.pop();
        pos = 0;
        while(ball[cur]>0 &&!q.empty()){
            t = q.top(); q.pop();
            ball[cur]--;
            ball[t] --;
            mat[cur][t] = mat[t][cur] = 1;
            ptr[pos++] = t;
        }
        if(ball[cur]!=0)
            return false;
        while(pos > 0){
            t = ptr[--pos];
            if(ball[t] > 0){
                q.push(t);
            }
        }
    }

    return true;
}
void output(){
    int i,j;
    for(i=0; i<num; i++){
        printf("%d", mat[i][0]);
        for(j=1; j<num; j++){
            printf(" %d", mat[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int tstnum = 0;
    while(readIn() > 0){
        if(tstnum++){
            printf("\n");
        }
        if(fun()){
            output();
        } else {
            printf("~><~\n");
        }
    }
    return 0;
}
