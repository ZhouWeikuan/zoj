#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){
    string s;
    string freq;
    int max;
    map<string,int> table;
    int num;
    
    cin>>num;
    while(num){
        max = 0;
        table.clear();        
        while(num--){
            cin>>s;
            if(++table[s] > max){
                max ++;
                freq = s;
            }            
        }
        cout<<s<<endl;
        cin>>num;    
    }    
 
    return 0;   
}
