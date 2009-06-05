#include<iostream>
#include<string>
#include<set>

using namespace std;

set<string> tab;

void search(string &s){
    cout<<s<<":";
    set<string> v;
    string ns;
    int i, j, len;
    // delete one
    for(i=0, len=s.length(); i<len; i++){
        ns = s.substr(0,i) + s.substr(i+1, len-i-1); 
        if(tab.find(ns) != tab.end()){
            v.insert(ns);
        }
    }
    // replace one
    for(i=0; i<len; i++){
        ns = s;
        for(j='a'; j<= 'z'; ++j){
            if(j == s[i]) continue;
            ns[i] = j;
            if(tab.find(ns) != tab.end()){
                v.insert(ns);
            }
        }
    }
    // insert one
    for(i=0; i<=len; i++){
        string tmp = "a";
        for(tmp[0]='a'; tmp[0]<='z'; ++tmp[0]){
            ns = s.substr(0, i) + tmp + s.substr(i, len - i);
            if(tab.find(ns) != tab.end() ){
                v.insert(ns);
            }
        }
    }
    for(set<string>::iterator is=v.begin(); is!=v.end(); ++is){
        cout<<" "<<*is;
    }
    cout<<"\n";
}

void fun(){
    string s;
    cin>>s;
    while(s!="#"){
        if(tab.find(s)!=tab.end()){
            cout<<s<<" is correct\n";
        } else{
            search(s);
        }
        cin>>s;
    }
}
void readIn(){
    string s;
    tab.clear();

    cin>>s;
    while(s!="#"){
        tab.insert(s);
        cin>>s;
    }
}
int main(){
    int tst;

    scanf("%d", &tst);
    while(tst--){
        readIn();
        fun();
        if(tst) cout<<"\n";
    }
    return 0;
}

