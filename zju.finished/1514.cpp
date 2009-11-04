#include<iostream>
#include<set>

using namespace std;
set<int> table;
set<int> dup;

int main(){
    int N,M;
    int i;
    int value;
    int fake;
    
    cin>>N>>M;
    while(N ){
        table.clear();
        dup.clear();
        
        for(i=0;i<M;i++){
            cin>> value;
            if(table.find(value) != table.end()){
                dup.insert(value);
            } else {
                table.insert(value);
            }            
        }
        cout<<dup.size()<<endl;
        cin>>N>>M;
    }
    
 
    return 0;   
}
