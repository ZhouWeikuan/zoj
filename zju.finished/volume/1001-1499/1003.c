#include<cstdio>

#include<map>

using namespace std;

map<int,int> m;
int keep[110];
int pos;

int log_b(int n, int start){
    int flag = 0;
    if(n ==1){
        pos ++;
        return 1;
    }
    if(start > n){
        return 0;
    }
    
    int least = n>100?100:n;
    int t = 0;
    
    while(start <= least){
        if(n %start ==0){
            m[start] ++;
            t = log_b(n/start,start+1);
            if(!t ){
                m[start]--;
            } else {
                flag = 1;
            }
        }
        start ++;
    }
    return flag;
}

/*获得n的表达形式中必不可少的元素，保存在数组中；如有重复，则均保存*/
int calc_b(int n){
    int i;
    int t;
    int least = n >100?100:n;
    int flag = n<=100?1:0;
    pos = 0;
    for(i=0;i<101;i++)
        keep[i] = 0;
    
    m.clear();
    for(i=2;i<=least;i++){
        if(n%i == 0){
            m[i] ++;
            t= log_b(n/i,i+1);
            if(!t){
                m[i]--;
            } else {
                flag = 1;
            }
        }
    }
    map<int,int>::iterator iter;
    for(iter=m.begin();iter!=m.end();iter++){
        if((*iter).second==pos){
            keep[(*iter).first] = 1;
        }
    }
    
    return flag;
}
int log_a(int n, int start){
    int flag = 0;
    if(n ==1){        
        return 1;
    }
    if(start > n){
        return 0;
    }
    
    int least = n>100?100:n;
    int t = 0;
    
    while(start <= least){
        if(n %start ==0 && keep[start] == 0){            
            t = log_a(n/start,start+1);
            if(t ){ 
                flag = 1;
            }
        }
        start ++;
    }
    return flag;
}

int calc_a(int n){
    int i;
    int t;
    int flag = 0;
    int least = n >100?100:n;
    for(i=2;i<=least;i++){
        if(n%i == 0 && keep[i] == 0){            
            t= log_a(n/i,i+1);
            if(t){
                flag = 1;
            }
        }
    }
    return flag;
}

int fun(int max,int min){    
    int a,b,c;
    int p;         
    
    if(max <= 100){
        return max;
    }
    
    b = calc_b(min);
    a = calc_a(max);    
        
    if(b == 0)  /*不成立，则较低分数者不可信*/
        return max;
    if(a == 0)  /*不成立，则较高分数不可信*/
        return min;
    return max;        
}


int main(){
    int a,b;
    int t;
    
    scanf("%d %d", &a,&b);
        
    while(!feof(stdin)){
        if(a < b){
            t = a;
            a = b;
            b = t;
        }
    
        t = fun(a,b);
        printf("%d\n",t);
        
        scanf("%d %d", &a,&b);
    
    }    
    
    return 0;
}
