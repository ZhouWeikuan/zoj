#include<iostream>
using namespace std;
enum {
    SIZ = 24,
};
// case 1. 如果两边均无法拓展，则输
// case 2. 如果仅一边能拓展，且拓展时将当前边改成>0的数，则
//       另一个可以沿当前边返回，并把边改为0,情况变为case 1,输。
//       因此，拓展时，必须把走的边改成0.
//       因此，如果能拓展奇数次，则赢，否则输
// case 3. 如果两边均能拓展，有一边为奇，则向此边拓展，情况变成case 2,赢
//       否则，两边均为偶。假设拓展时，将经过的边不改为0,则被别人返回，情况变成
//       case 2中偶数拓展，输。因此拓展时，必须将经过的边改成0；又因为两边均为
//       偶，因此向一边拓展时，情况变成case 2中的偶数拓展，输。
// 总结：计算向两边拓展时的次数，如果有一边为奇，则赢，否则输
int num;
int dat[SIZ];
int fun(){
    int i;
    int a=0, b=0;
    for(i=0; i<num&&dat[i]!=0; i++){ // 正方向的拓展次数
        a++;
    }
    for(i=num-1;i>=0&&dat[i]!=0; i--){ // 反方向的拓展次数
        b++;
    }
    return (a|b)&0x01;
}
void readIn(){
    scanf("%d", &num);
    for(int i=0; i<num; i++){
        scanf("%d", &dat[i]);
    }
}
int main(){
    int tst;
    const char *ans[2] = {"NO","YES"};
    scanf("%d", &tst);
    while(tst--){
        readIn();
        int t = fun();
        printf("%s\n", ans[t]);
    }
    return 0;
}
