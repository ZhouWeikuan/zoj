#include<iostream>
#include<iterator>
#include<set>
#include<map>
#include<string>
using namespace std;
struct Node {
    set<string> s;
    int c;
};
map<string, Node > tab;
typedef map<string, Node > ::iterator iter;
string o, s;

struct Cmp{
    bool operator()(iter &a, iter &b) const {
        set<string> &sa = a->second.s, &sb = b->second.s;
        if(a->second.c != b->second.c ){
            return a->second.c < b->second.c;
        }
        for(set<string>::iterator ia=sa.begin(), ib=sb.begin();
                ia!=sa.end()&&ib!=sb.end(); ++ia, ++ib){
            if(*ia!=*ib){
                return *ia > *ib;
            }
        }
        return false;
    }
}cmp;

void fun(){
    int num = -1,i;
    iter out[10];
    for(iter it=tab.begin(); it!=tab.end(); ++it){
        if(num < 0){
            out[++num] = it;
            // cout<<"push "<< it->first<<endl;
            continue;
        }
        for(i=num; i>=0; i--){
            if(cmp(out[i], it) == false){ // not less than
                break;
            }
            if(i < 4){
                // cout<<"shift "<< out[i]->first<<" right"<<endl;
                out[i+1] = out[i];
            }
        }
        if(i < 4){
            // cout<<"push "<<it->first<<" at "<<(i+1)<<endl;
            out[i+1] = it;
            num += (num<4);
        }
    }
    num++;
    int j;
    for(i=0; i<num; i++){
        cout<<"Group of size "<<(out[i]->second.c)<<": ";
        copy(out[i]->second.s.begin(), 
             out[i]->second.s.end(),
             ostream_iterator<string> (cout, " "));
        cout<<"."<<endl;
    }
}
int main(){
    Node one;
    iter it;
    while(cin>>s){
        o = s;
        sort(o.begin(), o.end());
        it = tab.find(o);
        if( it == tab.end() ){
            one.s.clear();
            one.s.insert(s);
            one.c = 1;
            tab.insert(make_pair(o, one));
        } else {
            it->second.s.insert(s);
            it->second.c++;
        }
    }
    fun();
    return 0;
}

