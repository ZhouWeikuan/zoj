#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int cube[204];
multimap<int, int, greater<int> > table;

void init(){
    int i,j,k;
    int index;
    int t;
    for(i=2;i<=200;i++){
        cube[i] = i * i * i;
    }
    
    for(i=2;i<=200;i++){
        for(j=i+1;j<=200;j++){
            for(k=j+1;k<=200;k++){
                t = cube[i] + cube[j] + cube[k];
                if(t > cube[200]){
                    break;
                } else {
                    index = (i<<16) + (j<<8) + k;
                    table.insert(pair<int,int> (t, index) );
                }
            }
        }
    }
    multimap<int, int, greater<int> >::iterator first, last;
    
    for(t=2;t<=200;t++){
        first = table.lower_bound(cube[t]);
        last = table.upper_bound(cube[t]);
        for(; first!= last; first ++){
            i = first->second >>16;
            j = (first->second >>8) &0xff;
            k = (first->second ) &0xff;
            cout<<"Cube = "<<t <<", Triple = ("<<i<<","<<j<<","<<k <<")"<<endl;
        }
    }    
}




int main(){
    
    init();
    return 0;
}
