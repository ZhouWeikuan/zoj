#include<iostream>

using namespace std;
enum {
    Kind = 5,
};
struct Node {
    double c;
    double p;
};
int mult[Kind] = {9,4,4,4,7};
Node tree[Kind];
char buf[20];
double C,F;

void trans(int pos){
    int n, cnt;
    n = strlen(buf);
    cnt = atoi(buf);
    switch(buf[n-1]){
    case 'g':
        cnt *= mult[pos];
    case 'C':
        tree[pos].c += cnt;
        break;
    default:
        tree[pos].p += cnt;
        break;
    }
}
void calc(){
    double c = 0, p = 0;
    int i;
    for(i=0;i<Kind;i++){
        c += tree[i].c;
        p += tree[i].p;
    }
    c *= 100;
    c /= (100 - p);

    p = tree[0].p * c / 100;
    p += tree[0].c;
    C += c;
    F += p;
}


int readIn(){
    int i;
    int n;
    n = 0; C = F = 0.0;
    for(;;){
        scanf("%s", buf);
        if(buf[0] == '-')
            break;
        memset(tree, 0, sizeof(tree));
        n ++;
        trans(0);
        for(i=1;i<Kind;i++){
            scanf("%s", buf);
            trans(i);
        }
        calc();
    }
    return n;
}

void fun(){
    double p = F / C;
    p *= 100;
    printf("%.0lf%%\n", p);
}

int main(){

    while(readIn()){
        fun();
    }

	return 0;
}
