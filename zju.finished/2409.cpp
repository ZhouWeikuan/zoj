#include<iostream>
#include<string>
#include<algorithm>
//反正5!也没多长时间，就运行它的全排列吧 
using namespace std;
enum {
    SIZ = 5,
};
string vlist[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
string tlist[] = {"C","D","H","S"};
struct Node {
    int val;
    int type;
    bool operator < (const Node&rhs)const {
        if(val != rhs.val)
            return val < rhs.val;
        return type<rhs.type;    
    }  
};
Node tree[SIZ];
int find(string l[], string & v){
    int r = 0;
    while(strcmp(l[r].c_str(), v.c_str())!=0){
        r++;
    }
    r++;
    return r;
}
void readIn(){
    string s;
    for(int i=0;i<SIZ;i++){
        string tm;
        cin>>s;
        tm += s[s.length()-1];
        tree[i].type = find(tlist, tm);
        s[s.length()-1] = 0;
        tree[i].val = find(vlist, s);
    }
}

bool check(){
    if(tree[0].type != tree[1].type){
        return false;
    }
    int v = 1;
    for(int i=2;i<4;i++){
        if(tree[1+i] < tree[1+v]){
            v = i;
        }
    }
    if(v == 1){
        if(tree[4] < tree[3]) {
            v += 3;
        }
    } else if(v==2){
        if(tree[4] < tree[2]){
            v += 3;
        }
    } else {
        if(tree[3] < tree[2]){
            v += 3;
        }        
    }
    v += tree[1].val;
    v--;
    v %= 13;
    v ++;
    return v == tree[0].val;
}

int fun(){
    static int tst = 0;    
    cout<<"Problem "<<++tst<<": ";
    sort(tree, tree+SIZ);
    while(!check()){
        next_permutation(tree, tree+SIZ);
    }
    cout<<vlist[tree[0].val-1]<<tlist[tree[0].type-1];
    for(int i=1;i<SIZ;i++){
        cout<<" "<< vlist[tree[i].val-1]<<tlist[tree[i].type-1];
    }
    cout<<endl;
}

int main(){
    int tstcase;
    //freopen("input.txt", "r", stdin);
    cin>>tstcase;
    while(tstcase --){
        readIn();
        fun();
    }
    
    return 0;
}
