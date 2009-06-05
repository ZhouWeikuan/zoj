#include<iostream>
#include<vector>
#include<map>
using namespace std;
enum {
    SIZ = 308,
};
struct Point{
    int x, y;
    bool operator<(const Point &rhs)const{
        if(x!=rhs.x) return x<rhs.x;
        return y<rhs.y;
    }
};
int num, pos;
Point pnt[SIZ];
bool mat[SIZ][SIZ];
vector<int> lst[SIZ];
bool theFirst;

int gcd(int a, int b){
    int t;
    if(a < b){
        t = a; a = b; b = t;
    }
    while(b != 0){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}
int getKey(int a, int b){
    int dy = pnt[a].y - pnt[b].y;
    int dx = pnt[a].x - pnt[b].x;
    a = gcd(dx, dy);
    dx /= a;
    dy /= a;
    return ((dy<<16)|dx);
}
void calc(int cur){
    int i, key, v;
    map<int, int> tab;
    map<int, int>::iterator it;
    pos = 0;
    for(i=cur+1; i<num; i++){
        if(mat[cur][i]) continue;
        key = getKey(cur, i);
        it = tab.find(key);
        if(it != tab.end()){
            v = it->second;
            lst[v].push_back(i);
        } else{
            v = pos++;
            lst[v].clear();
            lst[v].push_back(i);
            tab.insert(make_pair(key, v));
        }
    }
    for(v=0; v<pos; v++){
        if(lst[v].size()<2) continue;
        if(theFirst){
            theFirst = false;
            printf("The following lines were found:\n");
        }
        printf("(%4d,%4d)", pnt[cur].x, pnt[cur].y);
        for(vector<int>::iterator hi=lst[v].begin(); 
                hi != lst[v].end(); hi++){
            printf("(%4d,%4d)", pnt[*hi].x, pnt[*hi].y);
            for(vector<int>::iterator low=lst[v].begin();
                    low != hi; low++){
                mat[*low][*hi] = true;
            }
        }
        printf("\n");
    }
}
void fun(){
    memset(mat, false, sizeof(mat));
    sort(pnt, pnt + num);
    theFirst = true;
    for(int i=0; i<num; i++){
        calc(i);
    }
    if(theFirst){
        printf("No lines were found\n");
    }
}
int readIn(){
    num = 0;
    scanf("%d%d",&pnt[num].x, &pnt[num].y);
    while(pnt[num].x != 0 || pnt[num].y != 0){
        ++num;
        scanf("%d%d",&pnt[num].x, &pnt[num].y);
    }
    return num;
}
int main(){
    while( readIn() > 0 ){
        fun();
    }
    return 0;
}
