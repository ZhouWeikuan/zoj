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

bool TrimDiff(set<string> &a, set<string> &b){
    bool flag = false;
    set<string>::iterator si=a.begin();
    while(si != a.end())
    {
        if (b.find(*si) == b.end()){
            a.erase(si++);
            flag = true;
        } else {
            ++si;
        }
    }
    return flag;
}

bool TrimAnd(set<string> &a, set<string> &b){
    bool flag = false;
    set<string>::iterator si=a.begin();
    while(si != a.end())
    {
        if (b.find(*si) != b.end()){
            a.erase(si++);
            flag = true;
        } else {
            ++si;
        }
    }
    return flag;
}

void Update(const string&us, const string&ns)
{
    mat[us] = ns;
    for (int i=0; i<ss.size(); ++i){
        ss[i].Remove(us, ns);
    }

    for(map<string, set<string> >::iterator iter = ntab.begin();
            iter != ntab.end(); ++iter)
    {
        iter->second.erase(us);
    }

    users.erase(us);
    nicks.erase(ns);
}

bool CheckNicks(Snapshot &s){
    bool flag = false;
    map<string, set<string> >::iterator iter;
    if (s.n.size() == s.u.size()){
        for(map<string, set<string> >::iterator iter = ntab.begin();
                iter != ntab.end(); ++iter)
        {
            if (s.n.find(iter->first) != s.n.end()){
            } else {
                if (TrimAnd(iter->second, s.u)){
                    flag = true;
                }
            }
        }
    }

    for(set<string>::iterator it=s.n.begin();
            it!=s.n.end(); ++it){
        iter = ntab.find(*it);
        if (iter == ntab.end()) continue;
        if (TrimDiff(iter->second, s.u))
            flag = true;

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
        for(map<string, set<string> >::iterator iter = ntab.begin();
                iter != ntab.end(); ++iter)
        {
            if (iter->second.size() == 1){
                mat[*(iter->second.begin())] = iter->first;
                Update(*(iter->second.begin()), iter->first);
            }
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

    cin>>n;
    //n = 1;
    while(n--){
        readIn();
        fun();
        if (n)
            cout<<endl;
    }

    return 0;
}

