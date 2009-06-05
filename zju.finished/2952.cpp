#include<iostream>
#include<vector>
#include<set>
#include<iterator>
#include<algorithm>
using namespace std;

const long long LIM = 1ll<<31;
set<unsigned> v;

void fun(){
    long long s, i;
    for(i=2,s=i*i; s<LIM; ++i,s=i*i){
        for(; s<LIM; s*=i){
            v.insert((unsigned)s);
        }
    }
    copy(v.begin(), v.end(), ostream_iterator<unsigned>(cout, "\n"));
}

int main(){

    fun();
    return 0;
}

