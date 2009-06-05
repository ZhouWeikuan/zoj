#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
enum {
    SIZ = 38, // 
};
int num;
int face[6][4] = {  // direction for die.
    {2, 5, 3, 4},   //  0,
    {2, 4, 3, 5},   //  1,
    {1, 5, 0, 4},   //  2,
    {0, 5, 1, 4},   //  3,
    {0, 3, 1, 2},   //  4,
    {0, 2, 1, 3}    //  5,
};
struct Node {
    int ptr[6];
};
int mark[6];
Node tr[SIZ];
int st[SIZ], pos;

void tail(){
    int i, t;
    t = 2;
    for(i=0; i<6; i++){
        if(mark[i] == 0){
            st[t++] = i;
        }
    }
    do {
        for(i=0; i<6; i++){
            tr[pos].ptr[st[i]] = i;
        }
        pos++;
    } while(next_permutation(st+3, st+6));
}
void init(){    // permutate all possibilities.
    memset(mark, 0, sizeof(mark));
    st[0] = 0; mark[0] = 1;
    pos = 0;
    for(int i=1; i<6; i++){
        st[1] = i;
        mark[i] = 1;
        tail();
        mark[i] = 0;
    }
    // printf("%d\n", pos);
}

bool check(int p, int a, int b, int c){
    int i;
    a = tr[p].ptr[a];
    b = tr[p].ptr[b];
    c = tr[p].ptr[c];
    for(i=0; i<4; i++){
        if(face[a][i] == b)
            break;
    }
    if(i==4) return false;
    i = (i+1)%4;
    return (face[a][i] == c);
}
void fun(){    
    int i, j, a, b, c, t;
    for(i=0; i<pos; i++){
        st[i] = i;
    }
    t = pos;
    while(num--){
        scanf("%d%d%d",&a,&b,&c);
        a--, b--, c--;
        j = 0;
        for(i=0; i<t; i++){
            if(check(st[i], a, b, c)){
                st[j++] = st[i];
            }
        }
        t = j;
    }
    if(t > 1){
        printf("=.-\n");
    } else if(t == 1){
        j = st[0];
        for(i=0; i<6; i++){
            st[tr[j].ptr[i]] = i;
        }
        printf("%d", 1);
        for(i=1; i<6; i++){
            printf(" %d", st[i] + 1);
        }
        printf("\n");        
    } else {
        printf("T_T\n");
    }
}

int main(){
    init();
    
    while( scanf("%d",&num) > 0){
        fun();
    }
    return 0;
}

