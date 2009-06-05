#include<iostream>
#include<string>
#include<queue>
#include<set>

using namespace std;
enum {
    SIZ = 101,
};
string tree[SIZ];
set<string> tab;

void init(){
    queue<string> q;
    tree[1] = "1";
    tree[1][0] = 1;
    q.push(tree[1]);
    tab.insert(tree[1]);
    int i,j;
    int t, lim;
    while(! q.empty() ){
        string cur = q.front(); q.pop();
        lim = cur[cur.length() -1 ];
        for(i=cur.length()-1;i>=0;i--){
            for(j=i;j>=0;j--){
                t = cur[i] + cur[j];
                if(t >= SIZ || t < 0)
                    continue;
                if(t <= lim)
                    break;
                string one = cur;
                one += (char)t;
                if(tree[t].length() && one.length() > tree[t].length())
                    continue;
                if(tab.find(one) != tab.end())
                    continue;

                tab.insert(one);
                q.push(one);
                if(tree[t].length()==0 || one.length() < tree[t].length()){
                    tree[t] = one;
                }
            }
        }
    }

}

void output(int n){
    int i,t;
    cout<<1;
    for(i=1;i<tree[n].length();i++){
        t = tree[n][i];
        cout<<" "<<t;
    }
    cout<<endl;
}

int main(){
    init();
    int n;
    cin>>n;
    while( n > 0){
        output(n);
        cin>>n;
    }
	return 0;
}
