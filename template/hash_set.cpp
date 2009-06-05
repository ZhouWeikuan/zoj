#include<iostream>
#include<ext/hash_set>

using namespace std;
using namespace __gnu_cxx; 

hash_set<int>  tab;

int main(){
    
    for(int i=0;i<100;i++){
        tab.insert(2*i + 1);
    }
    for(hash_set<int>::iterator iter = tab.begin();
            iter!=tab.end();
            iter++){
        cout<<(*iter)<<" ";
    }
    cout<<endl;

	return 0;
}
