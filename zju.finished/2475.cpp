#include<iostream>
#include<vector>
using namespace std;
enum {
    SIZ = 104,    
};
vector<int> ptr[SIZ];
int mark[SIZ];
int num;

int visit(int v){
    if(mark[v]){
        return 1;
    }
    mark[v] = 1;
    for(int i=0;  i<ptr[v].size(); i++){
        if(visit(ptr[v][i])){
            return 1;
        }
    }
    mark[v] = 0;
    return 0;
}

int readIn(){
    cin>>num;
    if(num<0)
        return 0;
    int i,a,b;
    for(i=0;i<SIZ;i++){
        ptr[i].clear();
        mark[i] = 0;
    }
    for(i=0;i<num;i++){
        cin>>a>>b;
        if(a == b)
            continue;
        ptr[a].push_back(b);
    }
    
    return 1;
}

int fun(){
    int v;
    cin>>v;
    static const char *ans[2] = {"Yes","No"};
    cout<<ans[ visit(v) ]<<endl;
    return 0;    
}

int main(){
  
    while(readIn()){
        fun();
    }
    
	return 0;
}
