#include<iostream>
using namespace std;

// 自己的方法比较笨，从网上拷了好的方法。
enum {
    SIZ = 10,
    LIM = 48000,
};

/*
struct Node {
    int in;
    int out;
    float rate;
    bool operator < (const Node &rhs) const {
        return rate > rhs.rate;
    }
};

int num, val, year;
Node tree[SIZ];
int mat[SIZ][48000];

void readIn(){
    cin >>val>>year
        >>num;
    for(int i=0; i<num; i++){
        cin >> tree[i].in >> tree[i].out;
        tree[i].out += tree[i].in;
        tree[i].in  /= 1000;
        tree[i].rate = tree[i].out / tree[i].in;
    }
    sort(tree, tree+num);
    memset(mat, -1, sizeof(mat));
}

int dp(int s, int p){
    if(p >= num){
        return  s * 1000;
    }
    if(mat[p][s] >= 0){
        return mat[p][s];
    }
    int ret = 0, t, i;
    i = s / tree[p].in;
    while(i >= 0){
        t = tree[p].out * i + dp(s - i * tree[p].in, p+1);
        if(t > ret){
            ret = t;
        }else if(t < ret - tree[p].rate){
            break;
        }
        i--;
    }
    return mat[p][s] = ret;
}

int fun(){
    while( year --){
        val = val % 1000 + dp(val/1000, 0);
    }
    return val;
}
*/

/* 以下为抄袭部分 */
int in[SIZ], out[SIZ];
int m[LIM];
int num, val, year;

void readIn(){
    int i,j,t;
    cin>>val>>year>>num;
    for(i=0; i<num; i++){
        cin>>in[i]>>out[i];
        in[i] /= 1000;
    }
    memset(m, 0, sizeof(m));
    for(i=0; i<num; i++){
        t = in[i];
        if(t < LIM && m[t] < out[i]){
            m[t] = out[i];
        }
        for(j=1;j<LIM;j++){
            if(m[j] < m[j-1]) m[j] = m[j-1];
            t = j + in[i];
            if(t >= LIM) break;
            if(m[t] < m[j] + out[i]){
                m[t] = m[j] + out[i];
            }
        }
    }
}

int fun(){
    while(year--){
        val += m[val/1000];
    }
    return val;
}
/* 以上为抄袭部分 */
int main(){
    int tstcase;

    cin>>tstcase;
    while( tstcase --){
        readIn();
        cout<<fun()<<endl;
    }

    return 0;
}

