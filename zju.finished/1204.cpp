#include<iostream>
#include<ext/hash_set>
// 按照加数从2开始，测试n个加数是否可以形成一个存在的和 
// 效率还满高的:)
using namespace std;
using namespace __gnu_cxx;
enum {
    SIZ = 30,
};
hash_set<int> tab;
int maxSum;
int input[SIZ], num;
int ans[SIZ], top;

void output(int s){
    int i;
    printf("%d",input[ans[0]]);
    for(i=1;i<top;i++){
        printf("+%d",input[ans[i]]);
    }
    printf("=%d\n",s);
}
int add(int s){
    int i,j;
    i = top - 1;
    do {
        if(s > maxSum)
            --i;
        while(i>=0 && ans[i] + top - i >= num){
            --i;
        }
        if(i < 0)
            return 0;
        s -= input[ans[i]];
        ans[i]++;
        s += input[ans[i]];
        for(j=i+1;j<top;++j){
            s -= input[ans[j]];
            ans[j] = ans[j-1]+1;
            s += input[ans[j]];
        }
    } while(s > maxSum);
    return s;
}
int test(){
    int i,s=0;
    for(i=0;i<top;i++){
        ans[i] = i;
        s += input[i];
    }
    if(s > maxSum)
        return -1;
    int ret = 0;
    do {
        if(tab.find(s)!=tab.end()){
            output(s);
            ++ret;
        }
    } while( s=add(s));
    return ret;
}
void fun(){
    int t;
    int cnt = 0;
    for(top=2; top<num;++top){
        t = test();
        if(t < 0){
            break;
        }
        cnt += t;
    }
    if(cnt == 0){
        printf("Can't find any equations.\n");
        return;
    }
}
void readIn(){
    scanf("%d",&num);
    maxSum = 0;
    tab.clear();
    for(int i=0;i<num;i++){
        scanf("%d",&input[i]);
        tab.insert(input[i]);
    }
    sort(input, input+num);
    maxSum = input[num-1];
}
int main(){
    int tstcase;
    scanf("%d",&tstcase);
    while(tstcase--){
        readIn();
        fun();
        printf("\n");
    }

    return 0;
}

