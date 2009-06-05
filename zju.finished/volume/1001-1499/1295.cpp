#include<iostream>
#include<string>

using namespace std;

int main(){
    int tstcase;
    string str;
        
    str.reserve(80);
    scanf("%d\n",&tstcase);    
    while(tstcase--){
        getline(cin,str,'\n');
        reverse(str.begin(),str.end());
        cout<<str<<endl;
    }
    
    return 0;
}
