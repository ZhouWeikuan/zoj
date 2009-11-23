//此程序通过pku2195测试
/*参考资料:
http://baike.baidu.com/view/739278.htm
http://www.cmykrgb123.cn/blog/match-km/
*/
/*
   求二分图的最大权匹配
   算法输入：二维数组g[][]，N表示节点的个数(保证左右节点相等)
   算法输出：ans最大权匹配的值, pre[i]表示与右边节点i 匹配的节点为pre[i]
   说明：如果是求最小权匹配，则将边取反，求最大权匹配（如果原边小于0，先将所有的边加上一个大数）
   */
/*
   KM algorithm:
1:初始化顶标，lx[i] = max(lx[i], g[i][j]); ly[i] = 0;
2:不断更新顶标，直到找到导出子图的完备匹配
(导出子图是指lx[i]+ly[j] == g[i][j]的边+原图的构成的点所得到的图)
*/
#include <stdio.h>
#include <string.h>
enum {
    SIZ = 205,
    INF = (1<<31) - 1;
};

int  N;
int  g[SIZ][SIZ];
int  pre[SIZ];
int  lx[SIZ], ly[SIZ], slk[SIZ];
bool  vx[SIZ], vy[SIZ];

bool  dfs(int t) {
    int i;
    vx[t] = true;
    for(i = 0; i < N; i++){
        if(vy[i])
            continue;
        int  tmp = lx[t]+ly[i]-g[t][i];
        if(tmp == 0) {
            vy[i] = true;
            if(pre[i] == -1 || dfs(pre[i])) {
                pre[i] = t;
                return true;
            }
        } else if(slk[i] > tmp) {
            slk[i] = tmp;
        }
    }
    return false;
}

int  KM() {
    int  i, j, k;
    //ly[i] = 0, lx[i] = -INF;
    memset(lx, 0, sizeof(lx));
    memset(ly, 0, sizeof(ly));
    memset(pre, -1, sizeof(pre));
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            if(lx[i] < g[i][j])
                lx[i] = g[i][j];
    for(i = 0; i < N; i++)  {
        for(j = 0; j < N; j++)
            slk[i] = INF;
        while(1)  {
            memset(vx, false, sizeof(vx));
            memset(vy, false, sizeof(vy));
            if(dfs(i))
                break;
            int  d = INF;
            for(j = 0; j < N; j++)
                if(!vy[j] && d > slk[j])
                    d = slk[j];
            for(j = 0; j < N; j++)  {
                if(vx[j])
                    lx[j] -= d;
                if(vy[j])
                    ly[j] += d;
                else
                    slk[j] -= d;
            }
        }
    }
    int ans = 0;
    for(i = 0; i < N; i++)
        ans -= (lx[i]+ly[i]);
    return  ans;
}

int main(){

    while(readIn() > 0){
        fun();
    }

    return 0;
}

