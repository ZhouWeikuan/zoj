#include<iostream>
#include<set>
using namespace std;
set<int> tab;
set<int>::iterator it;
int n,m;

void fun() {
    int i,t;
    tab.clear();
    for(i=0;i<n;i++){
        cin>>t;
        tab.insert(t);
    }
    while(m--){
        cin>>t;
        it = tab.upper_bound(t);
        if(it==tab.begin()||it==tab.end()){
            cout<<"no such interval"<<endl;
        } else {
            t = *it;
            --it;
            cout<<"["<<*it<<","<<t<<")"<<endl;
        }
    }
    cout<<endl;
}

int main(){

    while(cin>>n>>m){
        fun();
    }
    return 0;
}
