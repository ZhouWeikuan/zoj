#include<iostream>
using namespace std;
enum {
    SIZ = 24,
};
struct Node {
    int from;
    int to;
    bool operator<(const Node&rhs) const {
        if(to != rhs.to){
            return to < rhs.to;
        }
        return from<rhs.from;
    }
};
char rank[6]="SMLXT";
int cnt[5];
int num, sum;
Node tree[SIZ];
int getRank(char c){
    for(int i=0;i<6;i++){
        if(rank[i] == c)
            return i;
    }
    return 6;
}
void readIn(){
    int i;
    static char buf[20];
    for(i=0;i<num;i++){
        cin>>buf;
        tree[i].from = getRank(buf[0]);
        tree[i].to = getRank(buf[1]);
    }
    sum = 0;
    for(i=0;i<5;i++){
        cin>>cnt[i];
        sum += cnt[i];
    }
    cin>>buf;
}
int fun(){
    if(sum < num)
        return 0;
    sort(tree, tree+num);
    int f = 0;
    for(int i=0;i<num;i++){
        f = 0;
        for(int j=tree[i].from;j<=tree[i].to; j++){
            if(cnt[j]> 0){
                cnt[j]--;
                f = 1;
                break;
            }
        }
        if(f ==0)
            return 0;
    }
    return 1;
}
int main(){
    string s;
    const char *ans[2]={
        "I'd rather not wear a shirt anyway...",
        "T-shirts rock!"
    };

    cin>>s;
    while(s!= "ENDOFINPUT"){
        cin>>num;
        readIn();
        cout<<ans[fun()]<<endl;
        cin>>s;
    }

    return 0;
}
