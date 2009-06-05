#include<cstdio>
//remember to keep the previous locations
// 每次的选择具有单调递增性
using namespace std;
enum {
    SIZ = 50004,
};
struct Node {
    int loc; // locations of previous max value.
    int val; // values on each point; 
    int sum;
};
Node mot[3];
int num, cap;
int coach[SIZ];
int sum[SIZ];
void init(){
    mot[0].loc = mot[1].loc = mot[2].loc = -1;
    mot[0].val = mot[1].val = mot[2].val = -1;
}

int mot2(int s){
    if(mot[2].loc >= s)
        return mot[2].sum;
    int val = -1, t;
    for( ; s<= num-cap; s++){
        if(sum[s] <= val)
            continue;
        val = sum[s];
        mot[2].loc = s;
    }
    mot[2].sum = val;
    return val;
}

int mot1(int s){
    if(mot[1].loc >= s){
        return mot[1].sum;
    }
    int val = -1,t;
    mot[1].val = -1;
    for( ; s<= num-2*cap; s++){
        if(sum[s] <= mot[1].val)
            continue;
        mot[1].val = sum[s];
        t = mot2(s + cap) ;
        t += mot[1].val;
        if(t > val){
            val = t;
            mot[1].loc = s;
        }
    }
    mot[1].sum = val;
    return val;
}

int mot0(){
    int val = 0, t;
    for(int i=0;i<=num-3*cap;i++){
        if(sum[i] <= mot[0].val)
            continue;
        mot[0].val = sum[i];
        t = mot1(i + cap);
        t += mot[0].val;
        if(val < t) {
            val = t;
        }
    }
    return val;
}

int fun(){
    init();
    return mot0();
}

void readIn(){
    int i, t=0;
    scanf("%d ", &num);
    for(i=0;i <num;i++){
        scanf("%d ", &coach[i]);
    }
    scanf("%d ", &cap);
    for(i=num-1;i>= num-cap; i--){
        t += coach[i];
    }
    sum[num-cap + 1] = 0;
    sum[num-cap] = t;
    for(i=num-cap-1;i>=0;i--){
        sum[i] = sum[i+1] + coach[i] - coach[i + cap];
    }
}

int main(){
    int tstcase;

    scanf("%d ", &tstcase);
    while(tstcase --){
        readIn();
        printf("%d\n", fun());
    }

	return 0;
}
