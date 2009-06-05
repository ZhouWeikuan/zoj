#include<cstdio>
#include<cmath>
#include<vector>
#include<set>

using namespace std;
enum {
    MaxSize = 500003,
};

int num;
int save[MaxSize] = {0,0,1,1,};
vector<int> divisor[MaxSize];

void calc(int n){
    if(save[n])
        return;
    if(n<2)
        return;    
    int div = (n/2 + 1);
    int i;
    set<int> s;
    int flag = 0;
    for(i=2;i<div;i++){
        div = n/i;
        if(n%i==0){            
            s.insert(i);            
            s.insert(div);     
            flag =1;       
            break;
        }
    }
    if(flag == 0){
        divisor[n].push_back(1);
        save[n] =1;
        return;
    }   
    calc(div);
    /* div * i == n */
    vector<int>::iterator iter;
    
    for(iter=divisor[div].begin();iter!=divisor[div].end();iter++){
        s.insert(*iter);
        int t = *iter * i;
        if(t <n)
            s.insert(t);
    }    
    
    set<int>::iterator siter;
    for(siter=s.begin();siter!=s.end();siter++){
        divisor[n].push_back(*siter);
        save[n] += *siter;
    }
    
}

void init(){
    divisor[1].push_back(1);
    divisor[2].push_back(1);
    divisor[3].push_back(1);        
}


void fun(){
    int value;
    calc(num);
    value = save[num];
    printf("%d\n",value);
    
}

int main(){
    int tstcase;    
    
    init();
    scanf("%d", &tstcase);
    while(tstcase --){
        scanf("%d",&num);
        fun();
    }    
    return 0;
}
