#include<iostream>
#include<string>
using namespace std;
enum {
    SIZ = 13,
};
string *tree[SIZ];
bool mark[1<<12];

bool test_mark(string &s){
    int t = 0;
    for(int i=0;s[i];i++){
        t *= 2;
        t += s[i]-'0';
    }
    if(mark[t])
        return true;
    mark[t] = true;
    return false;
}
bool check(string &a, string &b, int t){
    int i,v=0;
    for(i=0;a[i];i++){
        if(a[i]!=b[i])
            v++;
    }
    return v<t;
}
bool test_val(string *t, int k, int v, int lim){
    if(k==0)
        return false;
    bool ret =  check(t[k], t[k-1],v);
    if(k==lim-1){
        ret &= check(t[k],t[0],v);
    }
    return ret;
}
void init(){
    int i,j,p,base;
    for(i=2;i<SIZ;i++){
        tree[i] = new string[1<<i];
    }
    tree[2][0] = "00"; tree[2][1]="10";tree[2][2]="01";tree[2][3]="11";
    for(i=3;i<SIZ;i++){
        if(i%2==1){
            base = 1<<(i-1);
            for(j=0;j<base;j++){
                tree[i][j] = tree[i-1][j];
                tree[i][j] += "0";
            }
            for(j=0;j<base;j++){
                tree[i][j + base] = tree[i-1][j];
                tree[i][j + base] += "1";
            }
        } else {
            base = 1<<(i-2);
            int k = p = 0;
            memset(mark, 0, sizeof(mark));
            for(int x=0;x<4;x++){
                for(j=0;j<base;j++){
                    tree[i][j+base*x] = tree[i-2][j];
                    tree[i][j+base*x] += tree[2][(k+x)%4];
                    if(test_val(tree[i],j+base*x, i/2, 1<<i)
                            || test_mark(tree[i][j+base*x])){
                        exit(-1);
                    }
                    if(++k>=4){
                        k = 0;
                    }
                }
            }
        }
    }
}
void clean(){
    for(int i=2;i<SIZ;i++){
        delete [] tree[i];
    }
}

void fun(int n){
    int i,base;
    base = 1<<n;
    for(i=0;i<base;i++){
        printf("%s\n", tree[n][i].c_str());
    }
}

int main(){
    init();
    int n, tstcase=0;
    while(cin>>n && n > 0){
        if(tstcase++)
            printf("\n");
        fun(n);
    }

    clean();
    return 0;
}
