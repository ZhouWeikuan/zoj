#include<iostream>

using namespace std;
enum {
    SIZ = 32000,
};
unsigned len[SIZ];
unsigned sum[SIZ];
unsigned line, num, dig;

void init(){
    int t,i;
    len[0] = sum[0];
    for(i=1; i<10;i++){
        len[i] = len[i-1] + 1;
        sum[i] = sum[i-1] + len[i];
    }
    for(i=10; i<100;i++){
        len[i] = len[i-1] + 2;
        sum[i] = sum[i-1] + len[i];
    }
    for(i=100; i<1000;i++){
        len[i] = len[i-1] + 3;
        sum[i] = sum[i-1] + len[i];
    }
    for(i=1000; i<10000;i++){
        len[i] = len[i-1] + 4;
        sum[i] = sum[i-1] + len[i];
    }
    for(i=10000; i<SIZ;i++){
        len[i] = len[i-1] + 5;
        sum[i] = sum[i-1] + len[i];
    }
}

// get the first whose number is >= the line
void count_num(){
    int low=0, high = SIZ;
    int mid = (low + high) /2;
    while(low < high){
        if(sum[mid] == line){
            break;
        } else if(sum[mid] < line){
            low = mid + 1;
        } else {
            high = mid;
        }
        mid = (low + high) /2;
    }
    num = mid;
    line -= sum[mid-1];
}

void count_dig(){
    int low =0, high = num;
    int mid = (low + high) /2;
    while(low < high){
        if(len[mid] == line){
            break;
        } else if(len[mid] < line){
            low = mid + 1;
        } else {
            high = mid;
        }
        mid = (low + high) / 2;
    }
    line -= len[mid-1];
    dig = mid;
}

char fun(){
    static char buf[20];
    count_num();
    count_dig();
    sprintf(buf, "%d", dig);
    return buf[line - 1];
}

int main(){
    int tstcase;
    init();
    /*
    for(int i=1;i<=50256;i++){
        line = i;
        cout<<fun();
    }
    cout<<endl;
    return 0; */
    cin>>tstcase;
    while(tstcase --){
        cin>>line;
        cout<<fun()<<endl;
    }

	return 0;
}
