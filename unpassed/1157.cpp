#include<iostream>
#include<queue>
#include<set>
#include<map>
#include<string>
using namespace std;
// should be bipart

set<string> e;
map<string, int> r;
multimap<string, string> h;
vector<string> v;

bool dfs(string &s){
    e.insert(s);
    v.push_back(s);
    for(multimap<string,string>::iterator it=h.lower_bound(s); 
            it!=h.end()&&it->first==s; ++it){
        if(e.find(it->second) != e.end()){
            continue;
        }
        map<string, int>::iterator mi = r.find(it->second);
        if(mi != r.end()){
            /*
            v.push_back(it->second);
            reverse(v.begin(), v.end());
            for(vector<string>::iterator vi=v.begin(); vi!=v.end(); vi++){
                cout<<*vi<<" ";
            }
            cout<<endl;
            */
            if(--mi->second<=0){
                r.erase(mi);
            }
            return true;
        } else if(dfs(it->second)){
            return true;
        }
    }
    v.pop_back();
    return false;
}
void fun(){
    queue<string> q;
    for(set<string>::iterator i=e.begin(); i!=e.end(); ++i){
        q.push(*i);
    }
    string a;
    while(!q.empty()){
        a = q.front(); q.pop();
        e.clear();
        v.clear();
        dfs(a);
    }
    int n = 0;
    for(map<string,int>::iterator it=r.begin(); it!=r.end(); ++it){
        n += it->second;
    }

    cout<<n<<endl;
}

void readIn(){
    int n;
    e.clear();
    r.clear();
    h.clear();
    string a, b;

    cin>>n;
    while(n--){ // type of plug
        cin>>a;
        e.insert(a);
    }
    cin>>n;
    while(n--){ // type of device
        cin>>a>>b;
        if(e.find(b) != e.end()){
            e.erase(b);
        } else {
            r[b]++;
        }
    }
    cin>>n;
    while(n--){ // type of adapter
        cin>>a>>b;
        //h.insert(make_pair(a,b));
        h.insert(make_pair(b,a));
    }
}
int main(){
    int tst=1;
    cin>>tst;
    while(tst--){
        readIn();
        fun();
    }
    return 0;
}

