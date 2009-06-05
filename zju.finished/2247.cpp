#include<iostream>
#include<string>
#include<map>
using namespace std;
enum {
    SIZ = 3,
};
struct Node {
    int v;
    int t;
    bool operator<(const Node&rhs){
        if(t!=rhs.t){
            if(t < rhs.t)
                return true;
            return false;
        }
        if(v < rhs.v)
            return true;
        return false;
    }
};
Node tree[SIZ];
map<int,int> tab;
static char face[] = {'T','J','Q', 'K'};
static char suit[] = {'H','C','D', 'S'};
inline char v2f(char c){
    c += 12;
    c %= 13;
    c += 1;
    if(c<=9)
        return c +'0';
    c -= 10;
    return face[c];
}
inline char f2v(char c){
    if(c <= '9'){
        return c-'0';
    }
    for(int i=0;i<sizeof(face);i++){
        if(face[i] == c){
            return i + 10;
        }
    }
    return 0;
}
void convert(Node &one, string &s){
    int i;
    for(i=0;i<sizeof(suit);i++){
        if(s[1]== suit[i]){
            one.t = i;
            break;
        }
    }
    one.v = f2v(s[0]);
}

inline void insert(int a, int b, int v){
    int key = (a<<4)+b;
    tab[key] = v;
}
void init(){
    insert(0,2,1);
    insert(0,1,2);
    insert(1,2,3);
    insert(2,1,4);
    insert(1,0,5);
    insert(2,0,6);
}
char type, val;
void readIn(){
    string s;
    cin>>s;
    type = s[1];
    val = f2v(s[0]);
    for(int i=0;i<SIZ;i++){
        cin>>s;
        convert(tree[i], s);
    }
}
int getVal(){
    int a,b; // a->max, b->min
    if(tree[0] < tree[1]){
        a = 1; b = 0;
    } else {
        a = 0, b= 1;
    }
    if(tree[a] < tree[2]){
        a = 2;
    } else if(tree[2] < tree[b]){
        b = 2;
    }
    int key = (b<<4) + a;
    return tab[key];
}

int fun(){
    int t=getVal();
    val += t;
    val --;
    val %= 13;
    val ++;
    val = v2f(val);
    cout<<val<<type<<endl;
}

int main(){
    init();
    int tstcase;
    cin>>tstcase;
    while(tstcase --){
        readIn();
        fun();
    }

    return 0;
}
