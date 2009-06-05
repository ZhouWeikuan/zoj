#include<iostream>

using namespace std;
enum {
    MaxSize = 100005,
};
typedef unsigned long long u64_t;
int speed[MaxSize];
int num;

void fun(){
    u64_t sum = 0llu, t;
    u64_t first = speed[0];
    u64_t second = speed[1];
    t = first + second;
    
    while( num > 3){
		if(2*second > first + speed[num-2]){ // 判断是否由最快的人走两次
			sum += first * 2 + speed[num-1] + speed[num-2];			
		} else {
			sum += 2*second + first + speed[num-1];			
		}        
        num -= 2;        
    }
    if(num <= 2){
        sum += speed[num-1];        
    } else { /* num == 3 */
        sum += t;        
        sum += speed[num-1];        
    }
    cout<<sum<<endl;
}

int main(){
    int i;
    
    while( (scanf("%d",&num)) > 0){
        for(i=0;i<num;i++){
            scanf("%d", &speed[i]);
        }
        if(num){
            sort(speed, speed+num);
        	fun();
		} else {
            cout<<0<<endl;
		}
    }
    
    return 0;
}

