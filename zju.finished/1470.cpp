#include<iostream>
using namespace std;
enum {
    SIZ = 21,
};
int save[SIZ][SIZ][SIZ];

int calc(int v, int l, int d){
    if(save[v][l][d] != -1){
        return save[v][l][d];
    }
    if(v <= 0 || l <= 0 || d <= 0 || l > v){
        return save[v][l][d] = 0;
    }
    int cnt = 0;
    int a, b;
    for(int i=0;i<v;i++){
        for(int j=0;j<=i && j<=l;j++){
            // d-2, d-1
            a = calc(i, j, d-2);
            b = calc(v-i-1,l-j,d-1);
            cnt += a * b;
            // d-1, d-1
            a = calc(i, j, d-1);
            b = calc(v-i-1,l-j,d-1);
            cnt += a * b;
            // d-1, d-2
            a = calc(i, j, d-1);
            b = calc(v-i-1,l-j,d-2);
            cnt += a * b;
        }
    }
    return save[v][l][d] = cnt;
}

void init(){
    memset(save, -1, sizeof(save));
    save[1][1][1] = 1;
    save[0][0][0] = 1;
}

int main(){
    init();
    int v,l;
    int t, tmp;
    while(cin>>v>>l){
        t = 0;
        for(int i=0;i<=v;i++){
            tmp =   calc(v, l, i);
            t   +=  tmp;
        }
        cout<<t<<endl;
    }

    return 0;
}
