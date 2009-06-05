#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
struct Node {
    string name;
    int prob;
    int time;
    int geo;
    int sol[7];
    bool operator == (const Node &rhs) const {
        return (prob==rhs.prob)&&(time==rhs.time)&&(geo==rhs.geo);
    }
    bool operator<(const Node &rhs) const {
        if(prob != rhs.prob)
            return prob > rhs.prob;
        if(time != rhs.time)
            return time < rhs.time;
        if(geo != rhs.geo)
            return geo < rhs.geo;
        return name < rhs.name;
    }
};
int nlen, plen, tlen, glen, slen[7];
vector<vector<Node> > tree;
vector<Node> tmp;
Node one;

int calc(int val){
    static char buf[20];
    return sprintf(buf,"%d",val);
}
void init(){
    int num, p, t, g, s;
    cin>>num;
    while(num){
        tree.push_back(tmp);
        while(num--){
            cin>>one.name;
            if(one.name.length() > nlen){
                nlen = one.name.length();
            }
            one.prob = 0;
            one.time = 0;
            double geo = 0.0;
            for(int i=0;i<7;i++){
                cin>>one.sol[i];
                t = calc(one.sol[i]);
                if(t > slen[i]){
                    slen[i] = t;
                }
                if(one.sol[i] > 0){
                    one.prob ++;
                    one.time += one.sol[i];
                    geo += log((double)one.sol[i]);
                }
            }
            if(geo != 0.0){
                geo /= one.prob;
                geo = exp(geo);
                geo += 0.5;
            } else {
                geo = 0.0;
            }
            one.geo = (int)geo;
            t = calc(one.prob);
            if(plen < t){
                plen = t;
            }
            t = calc(one.time);
            if(tlen < t){
                tlen = t;
            }
            t = calc(one.geo);
            if(glen < t) glen = t;

            tree[tree.size()-1].push_back(one);
        }
        cin>>num;
    }
}
void fun(vector<Node> &cur){
    int rank = 0;
    sort(cur.begin(), cur.end());
    for(int i=0;i<cur.size();i++){
        if(i!=0 && cur[i] == cur[i-1]){
            ;
        } else {
            rank = i + 1;
        }
        printf("%02d", rank);
        printf(" %-*s", nlen,cur[i].name.c_str());
        printf(" %*d", plen,cur[i].prob);
        printf(" %*d", tlen,cur[i].time);
        printf(" %*d", glen,cur[i].geo);
        for(int j=0;j<7;j++){
            printf(" %*d", slen[j],cur[i].sol[j]);
        }
        printf("\n");
    }
}

int main(){

    init();
    for(int i=0;i<tree.size();i++){
        printf("CONTEST %d\n", i+1);
        fun(tree[i]);
    }
    return 0;
}
