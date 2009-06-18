#include<iostream>
#include<set>
#include<string>
using namespace std;

set<string> tab;

void calc(){
    int n; 
    string s;
    cin>>n;
    int r = 0;
    while(n--){
        cin>>s;
        r += (tab.find(s)!=tab.end());
    }
    cout<<r<<endl;
}

void fun(){
    int n;
    cin>>n;
    while(n--){
        calc();
    }
}

int readIn(){
    int n;
    string s;
    cin>>n;
    while(n--){
        cin>>s;
        tab.insert(s);
    }
    return n;
}

int main(){

    readIn();
    fun();
    return 0;
}

