#include<iostream>
#include<set>
#include<map>
#include<string>
#include<vector>
using namespace std;

map<string, string> mat;
set<string> users;
set<string> nicks;
map<string, set<string> > ntab;
struct Snapshot {
    set<string> u;
    set<string> n;
    void Remove(const string&us, const string&ns){
        u.erase(us); n.erase(ns);
    }
};

vector<Snapshot> ss;

char op;
string oper;

void Update(const string&us, const string&ns)
{
    mat[us] = ns;
    for (int i=0; i<ss.size(); ++i){
        ss[i].Remove(us, ns);
    }
    users.erase(us);
    nicks.erase(ns);
}

bool CheckNicks(Snapshot &s){
    map<string, set<string> >::iterator iter;
    bool flag = false;
    for(set<string>::iterator it=s.n.begin();
            it!=s.n.end(); ++it){
        iter = ntab.find(*it);
        if (iter == ntab.end()) continue;
        set<string>::iterator si=iter->second.begin();
        while(si != iter->second.end())
        {
            if (s.u.find(*si) == s.u.end()){
                iter->second.erase(si++);
                flag = true;
            } else {
                ++si;
            }
        }

        if (iter->second.size() == 1){
            Update(*iter->second.begin(), iter->first);
            ntab.erase(iter);
            flag = true;
        }
    }
    return flag;
}

void Query(){
    int i,j;
    Snapshot s;
    bool flag;
    ntab.clear();
    for (set<string>::iterator it=nicks.begin();
            it!=nicks.end(); ++it)
    {
        ntab.insert(make_pair(*it, users)); 
    }

    do {
        flag = false;
        for (i=0; i<ss.size(); ++i){
            if (CheckNicks(ss[i])){
                flag = true;
            }
        }
        if (users.size() == 1 && nicks.size() ==1){
            mat[*users.begin()] = *nicks.begin();
        }
    } while(flag);
}

void fun(){
    Snapshot s;
    while(cin>>op){
        if (op == 'M'){
            while(op=='M'){
                cin>>oper;
                s.n.insert(oper);
                cin>>op;
            }
            ss.push_back(s);
            s.n.clear();
        }
        if (op == 'Q') break;
        cin>>oper;
        if (op == 'E'){
            mat.insert(make_pair(oper, "???"));
            s.u.insert(oper);
            users.insert(oper);
        } else if (op == 'L'){
            s.u.erase(oper);
        } else { // can't arrive here
            int *a = 0;
            *a = 1;
        }
    }
    Query();
    for(map<string,string>::iterator it=mat.begin();
        it!=mat.end(); ++it){
        cout<<it->first<<":"<<it->second<<endl;
    }
}

void readIn(){
    int n;
    string s; 
    nicks.clear(); users.clear();
    mat.clear(); ss.clear();
    cin>>n;
    while(n--){
        cin>>s;
        nicks.insert(s);
    }
}

int main(){
    int n;

    //cin>>n;
    n = 1;
    while(n--){
        readIn();
        fun();
        if (n)
            cout<<endl;
    }

    return 0;
}

