#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

enum {
    SIZ = 24,
};
vector<string> name;
map<string, int> tab;
int mat[SIZ][SIZ];
int N,M;

void readIn(){
    int i;
    string a,b;
    name.clear(); tab.clear();
    memset(mat, 0, sizeof(mat));
    for(i=0;i<N;i++){
        cin>>a;
        name.push_back(a);
        tab[a] = i;
    }
    int t;
    int first, second;
    for(i=0;i<M;i++){
        cin>>a>>b>>t;
        first = tab[b];
        second = tab[a];
        if(first < second){
            mat[first][second] += t;
        } else {
            mat[second][first] -= t;
        }
    }
}   

int fun(){
    int a,b;
    for(a=1;a<N;a++){
        for(b=0;b<N;b++){
            mat[0][a] -= mat[a][b];
            mat[0][b] += mat[a][b];
            mat[a][b] = 0;
        }
    }
    for(a=1;a<N;a++){
        if(mat[0][a] > 0){
            cout<<name[0]<<" "<<name[a]<<" "<<mat[0][a]<<endl;
        } else {
            mat[0][a] = - mat[0][a];
            cout<<name[a]<<" "<<name[0]<<" "<<mat[0][a]<<endl;
        }
    }
}

int main(){
    int tstcase = 0; 
    cin>>N>>M;
    while(N+M){
        cout<<"Case #"<<++tstcase<<endl;
        readIn();
        fun();
        cout<<endl;
        cin>>N>>M;
    }

    return 0;
}
