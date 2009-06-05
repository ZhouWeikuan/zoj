#include<iostream>
#include<map>
#include<set>

using namespace std;
enum {
    SIZ = 21,
};

int num;
int mark[SIZ];
map<string,string> table;
map<string,string>::iterator iter;

void gen(string &k){
    for(int i=2;i<SIZ;i++){
        if(mark[i]== 0)
            continue;
        k += (char)i;
    }
}
void remove(set<int> &tab, int v){
    int t,i;
    for(t=v;t<SIZ;t+=v){
        if(mark[t] == 1){
            mark[t] =0;
            tab.insert(t);
        }
        for(i=2;i+t<SIZ;i++){
            if(mark[i] == 1)
                continue;
            if(mark[i+t] == 1){
                tab.insert(i+t);
                mark[i+t] = 0;
            }
        }
    }
}
void restore(set<int> &t){
    for(set<int>::iterator it=t.begin();
            it!=t.end();
            ++it){
        mark[*it] = 1;
    }
}
string fun(){	
    string key;
    gen(key);
	if(key.length() <= 1){
		return key;
    } else if( (iter=table.find(key) )!= table.end()){
        return iter->second;
    }
    string ret;
    for(int i=2;i<SIZ;i++){
        if(mark[i] == 0){
            continue;
        }
        set<int> tab;
        remove(tab, i);
        string t = fun();
        if(t[0] == 0){
            ret += (char)i;
        }
        restore(tab);
    }
    return table[key] = ret;
}

int main(){
    int tstnum = 0, tstcase;
    int t;
    string s;
    
    cin>>tstcase;
    while(tstnum < tstcase){
        memset(mark, 0, sizeof(mark));
        cin>>num;
		for(int i=0;i<num;i++){
            cin>>t;
            mark[t] = true;
        }
		cout<<"Scenario #"<<++tstnum<<":\n";
		s = fun();
		if( s[0] != 0 ){
			cout<<"The winning moves are:";
            for(t=0;t<s.length();t++){
                cout<<" "<<int(s[t]);
            }
            cout<<".\n";
		} else {
			cout<<"There is no winning move.\n";
		}
        cout<<endl;
	}    
    
    return 0;
}

