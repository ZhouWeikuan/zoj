#include<iostream>
#include<map>
#include<string>
using namespace std;
map<string, bool> tab;
map<string, bool>::iterator it ;

void init(){
    string s("1");
    s[0] = 1;
    tab.insert(make_pair(s, false) );
}

bool perm(string s){
    sort(s.begin(), s.end());
    it = tab.find(s);
    if(it != tab.end()){
        return it->second;
    }
    bool rv;
    for(int i=0; i<s.length(); i++){
        string n = s;
        while(n[i] > 1){
            n[i]--;
            rv = perm(n);
            if(rv == false ){// take several from one end.
                tab.insert(make_pair(s, true));
                return true;
            }
            if(n[i] > 1){
                for(int j=1; j<=n[i]/2; j++){ // take several from middle.
                    string v = n.substr(0, i) 
                        + n.substr(i+1, n.length()-i-1);
                    v += j;
                    v += (n[i] - j);
                    rv = perm(v);
                    if(rv == false){
                        tab.insert(make_pair(v, true));
                        return true;
                    }
                }
            }
        }
        n = n.substr(0, i) + n.substr(i+1, n.length()-i-1);//take all 
        rv = perm(n);
        if(rv == false ){
            tab.insert(make_pair(s, true));
            return true;
        }
    }
    tab.insert(make_pair(s, false));
    return false;
}

void fun(string &s){
    const char *ans[2] = {
        "No",
        "Yes"
    };
    printf("%s\n", ans[perm(s)]);
}
int readIn(string &s){
    int n, t;
    s = "";
    if(scanf("%d", &n)<0)
        return 0;
    for(; n>0; n--){
        scanf("%d", &t);
        s += t;
    }
    return 1;
}

int main(){
    string s;
    init();
    while(readIn(s) > 0){
        fun(s);
    }
    return 0;
}

