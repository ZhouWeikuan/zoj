#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;
enum {
    SIZ = 30,
};
struct Node {
    char alpha;
    int  x;
    int  y;
};
struct Edge {
    int num;
    int idx[SIZ];
};
Node tree[SIZ];
Edge row[SIZ];
Edge col[SIZ];
int num, rectnum;

struct Dot {
    int a;
    int b;
    int c;
    int d;
    struct cmp{
        int operator()(const Dot& a, const Dot &b){
            if(a.a != b.a)
                return tree[a.a].alpha < tree[b.a].alpha;
            if(a.b != b.b)
                return tree[a.b].alpha < tree[b.b].alpha;
            if(a.c != b.c)
                return tree[a.c].alpha < tree[b.c].alpha;
            return tree[a.d].alpha < tree[b.d].alpha;
        }
    };
};
vector<Dot> v;

int cmp(const Node *a, const Node *b){
    // big y first
    if(a->y != b->y)
        return b->y - a->y;
    // small x first
    return a->x - b->x;
}

int readIn(){
    cin>>num;
    for(int i=0; i<num; i++){
        cin>>tree[i].alpha >> tree[i].x >> tree[i].y;
    }

    return num;
}

void preprocess(){
    qsort(tree, num, sizeof(Node), 
            (int(*)(const void*, const void*))cmp);
    for(int i=0; i<num; i++){
        row[i].num = col[i].num = 0;
        for(int j=i+1; j<num; j++){
            if(tree[j].x == tree[i].x){
                col[i].idx[ col[i].num++ ] = j;
            }
            if(tree[j].y == tree[i].y){
                row[i].idx[ row[i].num++ ] = j;
            }
        }
    }
}

void printOut(){
    if(v.size() == 0)
        return;
    for(int i=0; i < v.size(); i++){
        if(i % 10 == 0)
            cout<<endl;
        Dot &t = v[i];
        cout<<" "<< tree[t.a].alpha
                 << tree[t.b].alpha
                 << tree[t.c].alpha
                 << tree[t.d].alpha;
    }
}

void addOut(int a, int b, int c, int d){
    Dot one = {a,b,c,d};
    v.push_back(one);
}

void calc(int a, int b){
    int i,j;
    int c,d;
    i = j = 0;
    while(i<col[a].num && j<col[b].num){
        d = col[a].idx[i];
        c = col[b].idx[j];
        if(tree[d].y == tree[c].y){
            addOut(a,b,c,d);
            i++,j++;
        }else if(tree[d].y < tree[c].y){
            j++;   
        } else {    
            i++;  
        }
    }
}

int fun(){
    static Dot::cmp mycmp;
    v.clear();
    for(int i=0;i<num;i++){
        for(int j=0;j< row[i].num; j++){
            calc(i, row[i].idx[j]);
        }
    }
    sort(v.begin(), v.end(), mycmp);
    printOut();
    return v.size();
}

int main(){
    int tstcase = 0;

    while(readIn()){
        cout<<"Point set "<<++tstcase<<":";
        preprocess();
        if( fun() == 0){
            cout<<" No rectangles";
        } 
        cout<<endl;
    }

	return 0;
}
