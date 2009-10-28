#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
enum {
    SIZ = 204,
};

int N, D;
string name[SIZ];
char buf[20];

int mat[20][20];

int calc(const char *a, int i, int n,
         const char *b, int j, int m){
    if (mat[i][j] != -1)
        return mat[i][j];
    if (i==n || j==m){
        return mat[i][j] = n-i + m -j;
    }
    // replace
    mat[i][j] = (a[i]!=b[j]) + calc(a,i+1,n, b,j+1,m);

    // the followings are for a[i]!=b[j]?
    // insert
    int t = 1 + calc(a, i, n, b, j+1, m);
    mat[i][j] = min(t, mat[i][j]);

    // delete
    t = 1 + calc(a, i+1, n, b, j, m);
    mat[i][j] = min(t, mat[i][j]);

    //swap
    if (i+2<=n && j+2<=m){
        if (a[i]==b[j+1] && a[i+1]==b[j]){
            t = 1 + calc(a, i+2, n, b, j+2, m);
            mat[i][j] = min(t, mat[i][j]);
        }
    }
    return mat[i][j];
}

int dis(string &a, string &b){
    memset(mat, -1, sizeof(mat));
    return calc(a.c_str(), 0, a.length(), b.c_str(), 0, b.length());
}

void fun(){
    int i, j, k;
    int ans = 0;
    bool flag = false;
    for (i=0; i<N; ++i){
        for (j=i+1; j<N; ++j){
            flag = false;
            k = dis(name[i], name[j]);
            if (k <= D){
                flag = true;
            }else if (D==2 && k<=3){
                int a, b;
                bool s = false;
                if (name[i].length() > name[j].length()){
                    swap(i,j);
                    s = true;
                }

                for (a=1; !flag && a < name[i].length(); ++a){
                    swap(name[i][a], name[i][a-1]);
                    k = dis(name[i], name[j]);
                    if (k <= 1) flag = true;
                    swap(name[i][a], name[i][a-1]);
                }

                if (s)
                    swap(i,j);
            }

            if (flag){
                printf("%s,%s\n", 
                        name[i].c_str(), 
                        name[j].c_str());
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
}

int readIn(){
    scanf("%d%d", &N, &D);
    if (N == 0) return 0;
    int i;
    for (i=0; i<N; ++i){
        scanf("%s", buf);
        name[i] = buf;
    }
    sort(name, name+N);

    return 1;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

