#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int num;    
    int tstcase = 0;
    string s;
    int i;
    vector<string> v;
        
    
    cin>>num;
    while(num){
        v.clear();
        cout<<"SET " << ++tstcase<<endl;
        while(num--){
            cin>>s;
            v.push_back(s);
        }
        num = v.size();
        for(i=0;i<num;i+=2){
            cout<<v[i]<<endl;
        }
        if(num%2 !=0){
            i-=3;
        } else {
            i--;
        }
        while(i>=0){
            cout<<v[i]<<endl;
            i-=2;
        }
        
        cin>>num;
    }
 
    return 0;   
}
