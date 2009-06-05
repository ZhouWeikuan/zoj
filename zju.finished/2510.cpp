#include<iostream>
#include<set>
// 贪心法，从网上看到。
// 排序后，从内到外，每次选择与内最接近的圆
using namespace std;
enum {
    SIZ = 10008,
    Enter = 0, 
    Exit = 1,
};
struct Event {
    int flag ; // Enter or Exit
    int val;
    int ptr;
    bool operator <(const Event &rhs) const {
        if(val != rhs.val)
            return val < rhs.val;
        return flag > rhs.flag;
    }
};
Event e[SIZ*2];
int num, sum;

int readIn(){
    if(scanf("%d",&sum) < 0)
        return 0;
    int a,b;
    num = 0;
    for(int i=0;i<sum;i++){
        scanf("%d%d",&a,&b);
        e[num].flag = Enter; e[num].val = a; e[num].ptr = i;
        num++;
        e[num].flag = Exit; e[num].val = b; e[num].ptr = i;
        num++;
    }
    sort(e, e+num);
    return 1;
}
int fun(){
    set<int> tab;
    int ret = 0;
    for(int i=0;i<num;i++){
        if(e[i].flag == Enter){
            tab.insert(e[i].ptr);
        } else {
            if(tab.find(e[i].ptr) != tab.end()){
                ret++;
                tab.clear();
            }
        }
    }
    return ret;
}
int main(){
    while(readIn() > 0){
        printf("%d\n", sum-fun());
    }
    return 0;
}
