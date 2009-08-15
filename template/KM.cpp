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
const  int MAXN = 200+5;  
const  int INF = (1<<31)-1;  
int  N;  

int  g[MAXN][MAXN];  
int  pre[MAXN];  
int  lx[MAXN], ly[MAXN], slack[MAXN];  
bool  visx[MAXN], visy[MAXN];  

bool  dfs(int t) {  
    int i;  
    visx[t] = true;  
    for(i = 0; i < N; i++){  
        if(visy[i]) 
            continue;  
        int  tmp = lx[t]+ly[i]-g[t][i];  
        if(tmp == 0) {  
            visy[i] = true;  
            if(pre[i] == -1 || dfs(pre[i])) {  
                pre[i] = t;  
                return true;  
            }  
        } else if(slack[i] > tmp) {  
            slack[i] = tmp;  
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
            slack[i] = INF;  
        while(1)  {  
            memset(visx, false, sizeof(visx));  
            memset(visy, false, sizeof(visy));  
            if(dfs(i)) 
                break;  
            int  d = INF;  
            for(j = 0; j < N; j++)  
                if(!visy[j] && d > slack[j])  
                    d = slack[j];  
            for(j = 0; j < N; j++)  {  
                if(visx[j]) 
                    lx[j] -= d;  
                if(visy[j]) 
                    ly[j] += d;  
                else 
                    slack[j] -= d;  
            }  
        }  
    }  
    int ans = 0;  
    for(i = 0; i < N; i++)  
        ans -= (lx[i]+ly[i]);  
    return  ans;  
}  

