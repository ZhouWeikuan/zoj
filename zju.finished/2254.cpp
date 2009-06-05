#include<iostream>
using namespace std;
// 步骤：
// 1.求出A中每个岛的顺序序列，即第i个岛在pos[i]时访问
// 2.求出B中每个岛的顺序，即第i次时访问tre[i].no岛
// 3.val[i]保存第i个共同访问的岛
// 4.遍历B中的每个岛B[i]，找到一个位置p,使得pos[val[p]]恰好>pos[B[i]]，并将
// val[p]替换为B[i]
enum {
    SIZ = 1008,
};
struct Node{
    int pro;
    int no;
    bool operator<(const Node&rhs) const {
        if(pro != rhs.pro) return pro < rhs.pro;
        return no < rhs.no;
    }
};
int num;
int pos[SIZ];
Node tre[SIZ];
int val[SIZ], vp;

int find(int v){
    int low = 0, hi = vp;
    int mid;
    while(low < hi){
        mid = (low+hi)/2;
        if(pos[val[mid]] < pos[v]){
            low = mid + 1;
        } else {
            hi = mid;
        }
    }
    return low;
}
int fun(){
    int i, t;
    vp = 0;
    for(i=0; i<num; i++){
        t = tre[i].no;
        if(vp == 0 || pos[val[vp-1]] < pos[t]){
            val[vp++] = t;
        } else {
            int v = find(t);
            val[v] = t;
        }
    }
    return vp;
}
int readIn(){
    scanf("%d", &num);
    if(num <= 0) return 0;
    int i;
    for(i=0; i<num; i++){
        scanf("%d", &tre[i].pro);
        tre[i].no = i;
    }
    sort(tre, tre+num);
    for(i=0; i<num; i++){
        pos[tre[i].no] = i;
    }
    for(i=0; i<num; i++){
        scanf("%d", &tre[i].pro);
        tre[i].no = i;
    }
    sort(tre, tre+num);
    return num;
}
int main(){
    while(readIn() > 0){
        printf("%d\n", fun());
    }
    return 0;
}
