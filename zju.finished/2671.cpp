#include<iostream>
using namespace std;
enum {
    SIZ = 30004,
};
int R, N, M;
struct Matrix{
    int a,b,c,d;
    void operator =(const Matrix& m){
        a = m.a; b = m.b; c=m.c; d=m.d;
    }
    void operator *=(const Matrix&m){
        Matrix o;
        o.a = (a*m.a+b*m.c)%R;
        o.b = (a*m.b+b*m.d)%R;
        o.c = (c*m.a+d*m.c)%R;
        o.d = (c*m.b+d*m.d)%R;
        *this = o;
    }
};
Matrix mat[SIZ];
struct SegTree{
    Matrix m;
    int lm, rm;
    SegTree *l, *r;
    SegTree(){}
    SegTree(int a, int b){
        create(a, b);
    }
    void create(int a, int b){
        l = r = 0;
        lm = a, rm = b;
        if(b == a+1){
            m = mat[a];
        } else {
            l = new SegTree(a, (b+a)/2);
            r = new SegTree((b+a)/2, b);
            m = l->m;
            m *= r->m;
        }
    }
    void find(int s, int e, Matrix &o){
        if(s == lm && e == rm){
            o = m;
            return;
        }
        int m = (lm+rm)/2;
        if(e <= m){
            l->find(s, e, o);
        } else if(s >= m){
            r->find(s, e, o);
        } else {
            Matrix x;
            l->find(s, m, o);
            r->find(m, e, x);
            o *= x;
        }
    }
    void clear(){
        if(l) l->clear();
        if(r) r->clear();
    }
};
SegTree head;

void fun(){
    head.create(0, N);
    int s, e;
    Matrix o;
    for(int i=0; i<M; i++){
        if(i) printf("\n");
        scanf("%d%d",&s,&e);
        s--;
        head.find(s,e,o);
        printf("%d %d\n%d %d\n", o.a, o.b, o.c, o.d);
    }
    head.clear();
}

int readIn(){
    if(scanf("%d%d%d",&R,&N,&M)<0)
        return 0;
    for(int i=0;i<N; i++){
        scanf("%d%d%d%d", &mat[i].a, &mat[i].b, &mat[i].c, &mat[i].d);
    }
    return 1;
}
int main(){
    int tst=0;
    while( readIn() > 0 ){
        if(tst++) printf("\n");
        fun();
    }
    return 0;
}

