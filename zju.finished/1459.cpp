#include<iostream>
//简单的动态规划，但注意下标的更改
enum {
	Size = 84,	
    Equal  = 0,
    Insert = 1,
    Delete = 2,
    Replace= 3,
};
using namespace std;

char fro[Size];
char to[Size];
int op[Size][Size];
int val[Size][Size];

int calc(int a, int b){
    if(fro[a]==0&& to[b]==0)
        return 0;
    if(val[a][b] >=0)
        return val[a][b];
    if(fro[a] == to[b]){
        op[a][b] = Equal;
        return val[a][b] = calc(a+1,b+1);
    }
    int t;
    if(fro[a] && to[b]){ // replace
        t = 1+ calc(a+1,b+1);
        if(val[a][b]<0 || t < val[a][b]){
            val[a][b] = t;
            op[a][b] = Replace;
        }
    }
    if(fro[a]){ // delete
        t = 1 + calc(a+1,b);
        if(val[a][b]<0|| t<val[a][b]){
            val[a][b] = t;
            op[a][b] = Delete;
        }
    }
    if(to[b]){// insert
        t = 1 + calc(a,b+1);
        if(val[a][b]<0|| t<val[a][b]){
            val[a][b] = t;
            op[a][b] = Insert;
        }
    }
    return val[a][b];
}

void fun(){
    memset(val, -1, sizeof(val));
    int d = calc(0,0);
    printf("%d\n",d);
    int i = 0, j = 0;
    int seq = 0;
    d = 0;
    while(fro[i] || to[j]){
        if(op[i][j] == Equal){
            i++,j++;
            continue;
        }
        printf("%d ", ++seq);
        if(op[i][j] == Insert){
            printf("Insert %d,%c\n",(j+1),to[j]);
            d--;
            j++;
        } else if(op[i][j] == Delete){
            printf("Delete %d\n",(i-d+1));
            d++;
            i++;
        } else { // replace
            printf("Replace %d,%c\n",(i-d+1),to[j]);
            i++,j++;
        }
    }
    
}
int main(){
    
    while(scanf("%s%s",fro,to) > 0){
		fun();		
	}
    return 0;
}
