#include<cstdio>
#include<map>

using namespace std;

map<long long, int> table;

void init(){
    long long x = 0, y = 0;
    int num = 0;
    long long key;
        
    while(x < 5004 && y < 5004){
        key = (x<<16) + y;
        table[key] = num ++;  /* 0 */
        x++, y++;
        
        key = (x<<16) + y;
        table[key] = num ++;  /* 1 */        
        x++, y--;
        
        key = (x<<16) + y;
        table[key] = num ++;  /* 2 */
        x++, y++;
        
        key = (x<<16) + y;
        table[key] = num ++;  /* 3 */
        x--, y++;
    }
    
}

int main(){
    int num,x,y;
    long long key;
    init(); 
    
    scanf("%d", &num);
    while(num --){
        scanf("%d %d ", &x, &y);
        key = x;
        key <<= 16;
        key += y;
        if(table.find(key) != table.end()){
            printf("%d\n", table[key]);
        } else {
            printf("No Number\n");
        }        
    }
 
    return 0;   
}
