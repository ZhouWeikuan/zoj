#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int p1,p2,p3;
int stopno;

void fun(){
    int i;
    long long n;
    long long value;
    priority_queue<long long, vector<long long>, greater<long long> > que;
    set<long long> table;
    
    i = 0;
    que.push(p1);
    que.push(p2);
    que.push(p3);
    table.insert(p1);
    table.insert(p2);
    table.insert(p3);
    
    while(i < stopno){
        n = que.top();
        que.pop();
        
        value = n * p1;
        if(value > 0 && table.find(value) == table.end()){
            que.push(value);
            table.insert(value);
        }
        
        value = n * p2;
        if(value > 0 && table.find(value) == table.end()){
            que.push(value);
            table.insert(value);
        }
        
        value = n * p3;
        if(value > 0 && table.find(value) == table.end()){
            que.push(value);
            table.insert(value);
        }
        i ++;
    }
    cout<< n << endl;
}

int main(){
    
    while(cin>>p1>>p2>>p3>>stopno){
        fun();        
    }
    return 0;    
}
