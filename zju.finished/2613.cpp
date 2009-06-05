#include<cstdio>
#include<cstring>
#include<string>

using namespace std;
// WRONG ANSWER
struct Node {
    int count; // count
    int update; // indicate whether it is occupied;
    char name[40];
};
enum {
    SIZ = 10004,
};
Node tree[SIZ];
int tstcase = 0;
int price,num;

int fun(){
    int r = 0;
    tree[r].count = SIZ;

    scanf("%d%d", &price, &num);
    char buf[40];
    int p;
    for(int i=0;i<num;i++){
        scanf("%s%d", buf, &p);
        if(p > price || p <= 0){
            ;
        } else if(tree[p].update < tstcase){
            Node &t = tree[p];
            t.update = tstcase;
            t.count= 1;
            strcpy(t.name, buf);
        } else {
            tree[p].count ++;
        }
    }
    for(int i=1;i<=price;i++){
        if(tree[i].update < tstcase)
            continue;
        if(tree[i].count < tree[r].count)
            r = i;
    }
    return r;
}

int main(){
    int tstnum;
    int root ;
    scanf("%d",&tstnum);

    while(tstcase ++ < tstnum){
        root = fun();
        printf("Case %d:\n", tstcase);
        printf("The winner is %s.\n", tree[root].name);
        printf("The price is %d.\n", root);
        if(tstcase < tstnum)
            printf("\n");
    }
    
	return 0;
}
