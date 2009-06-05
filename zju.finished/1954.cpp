#include<iostream>
#include<map>

using namespace std;
enum {
    SIZ= 100001,
};
struct Mark {
    int low;
    int high;
};
Mark save[SIZ+2];
void init(){
    map<int,Mark> tab;
    map<int,Mark>::iterator iter;
    Mark one = {0,0};
    tab[0] = one;
    int cur = 1;
    int low,high;
    low = high = 0;
    save[cur] = one;
    while(cur++ < SIZ){
        //from high to lowest
        iter = tab.end(); iter--;
        while(cur < SIZ && iter != tab.end()){
            one.low = iter->first;
            one.high = ++(iter->second.high);
            save[cur] = one;
            cur ++;
            iter = tab.find(iter->first-1);
        }
        if(cur >= SIZ)
            break;
        low --;
        one.low = 0;
        one.high = high + 1;
        tab[low] = one;
        one.low = low;
        
        while(cur < SIZ && one.high >=0){
            save[cur] = one;
            cur ++;
            one.high --;
        }

        if(cur >= SIZ)
            break;
        // from low to highest
        iter = tab.begin(); iter++;
        while(cur < SIZ && iter!= tab.end()){
            one.low = iter->first;
            one.high = --(iter->second.low);
            save[cur] = one;
            cur ++;
            iter = tab.find(iter->first+1);
        }

        if(cur >= SIZ)
            break;
        high ++;
        one.low = low;
        one.high = 0;
        tab[high] = one;
        one.high = low; one.low = high;
        while(cur<SIZ && one.high <= 0){
            save[cur] = one;
            cur ++;
            one.high ++;
        }
        cur --;
        if(cur >= SIZ)
            break;
    }

}
int main(){
    int n;
    init();

    while(cin>>n){
        cout<<save[n].low<<" "<<save[n].high<<endl;
    }

	return 0;
}
