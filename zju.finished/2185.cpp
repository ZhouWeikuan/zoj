#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

int find(int n){
    int low =1, hi =5000;
    int mid;
    
    while(hi > low){
        mid = (hi+low)/2;
        if(mid * (mid+1) < 2*n){
            low = mid + 1;
        } else {
            hi = mid;
        }        
    }
    if(hi == low){
        mid = low;
    }
    return mid;
}

int fun(int num){	
    int n,left;
    int hi,low;
	n = find(num) - 1;
    left = num - (n+1)*n/2;
    n ++;
    if(n%2==1){
        low = left;
        hi = (n+1) - low;
    } else {
        hi = left;
        low = (n+1) -hi;
    }
                      
    printf("TERM %d IS %d/%d\n", num, hi, low);
}

int main(){
    int num;      
    
	while(cin>>num){
		fun(num);
	}
 
    return 0;   
}
