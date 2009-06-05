#include<cstdio>
// TLE
//  从衡阳八中拷贝思想： sum[i]表示从第1个到第i个元素和
//  如果a[i+1] ... a[j] 和除尽m，则 sum[i] 与sum[j]同余相等
//  因此，只要统计sum[1]到sum[n]，计算出现每个数值的个数为n的C(n,2)即可
//  但数值0是特例，因为其本身也可视为独立一段。
using namespace std;
enum {
    SN = 5004,
};
int n,m;
int cnt[SN];

void readIn(){
    int t,i;
    int s = 0;
    for(i=0;i < m;i++)
        cnt[i] = 0;
    for( i=0; i<n; i++){
        scanf("%d",&t);
        s = (s + t) % m;
        cnt[s] ++;
    }
}
int fun(){
    int i,t;
    int ret = 0;
    for(i=0;i<m;i++){
        t = cnt[i];
        ret += t * (t-1);
    }
    ret /= 2;
    ret += cnt[0];

    return ret;
}

int main(){

    while(scanf("%d%d",&n,&m) > 0){
        readIn();
        printf("%d\n", fun());
    }

	return 0;
}
