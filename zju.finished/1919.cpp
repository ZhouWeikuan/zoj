#include<iostream>
#include<string>
#include<queue>
#include<set>
using namespace std;
// euler path for Directed Graph
enum {
    SIZ = 32,
};
int in[SIZ];
int out[SIZ];
int mat[SIZ][SIZ];
set<string> alp[SIZ];
bool mark[SIZ] = {false};

bool bfs(int s){
    memset(mark, false, sizeof(mark));
    mark[s] = true;
    queue<int> q;
    q.push(s);
    int i;
    while(!q.empty()){
        s = q.front(); q.pop();
        for(i=0; i<SIZ; i++){
            if(mark[i] == false && mat[s][i]){
                q.push(i);
                mark[i] = true;
            }
        }
    }
    for(i=0; i<SIZ; i++){
        if(in[i] || out[i]){
            if(mark[i] == false) 
                return false;
        }
    }
    return true;
}
int euler_path(){
    int f=-1, e=-1, i;
    for(i=0; i<SIZ; i++){
        if(in[i]!=out[i]){
            if(in[i] == out[i]-1){
                if(f >= 0){
                    return -1;
                } else {
                    f = i;
                }
            } else if(in[i]-1 == out[i]){
                if( e >= 0){
                    return -1;
                } else {
                    e = i;
                }
            } else {
                return -1;
            }
        }
    }
    if(e >= 0 && f>=0 && bfs(f)){
        return f;
    } else if(f==-1 && e==-1){
        for(f=0; f<SIZ; f++){
            if(alp[f].size() == 0) continue;
            if( bfs(f)){
                return f;
            } else {
                return -1;
            }
        }
        return 0;
    }
    return -1;
}
void fun(){
    int f = euler_path();
    if( f < 0){
        cout<<"***"<<endl;
        return;
    }
    int i;
    bool first = true;
    set<string>::iterator it;
    while(alp[f].size()){
        for(it=alp[f].begin();it!=alp[f].end(); ++it){
            i = (*it)[it->length()-1] - 'a';
            if(f == i){
                out[f]--, in[i]--;
                break;
            } else {
                mat[f][i]--;
                out[f]--, in[i]--;
                if(bfs(i)){
                    break;
                }
                mat[f][i]++;
                out[f]++, in[i]++;
            }
        }
        if(first){
            first = false;
            cout<<*it;
        } else {
            cout<<"."<<*it;
        }
        alp[f].erase(it);
        f = i;
    }
    cout<<endl;
}

void readIn(){
    int num, i, o;
    for(i=0; i<SIZ; i++){
        alp[i].clear();
    }
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    memset(mat, 0, sizeof(mat));
    string s;
    scanf("%d", &num);
    while(num--){
        cin>>s;
        o = s[0] - 'a';
        i = s[s.length()-1] - 'a';
        alp[o].insert(s);
        out[o]++;
        in[i]++;
        if(o!= i) mat[o][i]++;
    }
}
int main(){
    int tst;
    cin>>tst;
    while(tst--){
        readIn();
        fun();
    }
    return 0;
}

