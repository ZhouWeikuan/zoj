#include<iostream>
#include<queue>
using namespace std;
// TLE
enum {
    SIZ = 108,
};
int num;
int mat[SIZ][SIZ];
bool use[SIZ];

int check(int s, int e){
    int i;
    memset(use, false, sizeof(use));
    use[s] = true;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        s = q.front(); q.pop();
        for(int i=0; i<num; i++){
            if(mat[s][i] && use[i] == false){
                use[i] = true;
                q.push(i);
            }
        }
    }
    return (use[e]==true);
}

void fun(){
    char op;
    int a, b;
    memset(mat, 0, sizeof(mat));
    scanf(" %c", &op);
    while(op != 'X'){
        scanf("%d%d",&a,&b);
        if(op == 'N'){
            mat[a][b]++;
            mat[b][a]++;
        }else if(op == 'D'){
            mat[a][b]--;
            mat[b][a]--;
        }else if(op == 'C'){
            mat[a][b]--;
        }else if(op == 'O'){
            mat[a][b]++;
        }else if(op == 'Q'){
            printf("%d\n", check(a,b));
        }
        scanf(" %c", &op);
    }
}
int main(){
    while( scanf("%d",&num) > 0){
        fun();
    }
    return 0;
}
