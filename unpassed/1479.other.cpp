#include<stdio.h>
#include<string.h>
#include <algorithm>

using namespace std;

typedef struct {
    int x, y, num;
} DataType;

char map[25][25];
DataType heap[1000];

struct {
    int x, y;
    char dic;
}que[1000];

int m, n, p, px, py, cx, cy, len, flag, hash[25][25];
int dic[8][2] = {
    { -1, -1}, { -1, 0}, { -1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}
};
int mat[30][30];
int cmp (const DataType &a, const DataType &b) {
    return a.num > b.num;
}

void makemap() //读入地图信息，将激光处用'r'表示
{
    int i, j, k;
    
    for (i = 1;i <= p;i++) {
        switch (que[i].dic) { 
            case'u': 
                for (j = que[i].x - 1, k = que[i].y, map[j+1][k] = 'B';map[j][k] != 'B';)
                {
                    map[j][k] = 'r';
                    j--;
                }break;
                
            case'd': 
                for (j = que[i].x + 1, k = que[i].y, map[j-1][k] = 'B';map[j][k] != 'B';)
                {
                    map[j][k] = 'r';
                    j++;
                }break;
                
            case'l': 
                for (j = que[i].y - 1, k = que[i].x, map[k][j+1] = 'B';map[k][j] != 'B';)
                {
                    map[k][j] = 'r';
                    j--;
                }break;
                
            case'r': 
                for (j = que[i].y + 1, k = que[i].x, map[k][j-1] = 'B';map[k][j] != 'B';)
                {
                    map[k][j] = 'r';
                    j++;
                }break;
        }
    }
}

int min (int a, int b) {
    if (a > b)
        return b;
    else
        return a;
}

int find (int x, int y)  //判断扩展出的点是否在优先队列里
{
    int i; 
    for (i = 0;i <= len;i++)
        if (heap[len].x == x && heap[len].y == y) {
            flag = len;
            return 1;
        }
        
    return 0;
}

int BFS()
{
    int i, j, k, x, y, num, xx, yy;
    memset (hash, 0, sizeof (hash) );
    memset(mat, -1, sizeof(mat));
    heap[0].x = px;
    heap[0].y = py;
    heap[0].num = 0;
    len = 1;
    
    while (len != 0)
    {
        x = heap[0].x;
        y = heap[0].y;
        num = heap[0].num;
        mat[x][y] = num;
        hash[x][y] = 1;
        
        if (x == cx && y == cy)
            return num;  //如果找到孩子所在位置，则返回此位置的淋水次数
            
        std::pop_heap (heap, heap + (len--), cmp);
        
        for (i = 0;i < 8;i++)   //在八个方向上扩展
        {
            xx = x + dic[i][0];
            yy = y + dic[i][1];
            
            if (hash[xx][yy] == 0)
            {
                if (map[xx][yy] == 'b') //扩展位置为空位置
                {
                    if (find (xx, yy) == 0)
                    {
                        heap[len].x = xx;
                        heap[len].y = yy;
                        heap[len].num = num;
                        len++;
                    }
                    else
                        heap[flag].num = min (num, heap[flag].num);
                }
                else
                    if (map[xx][yy] == 'r' && map[x][y] != 'r')  //扩展位置为激光
                    {
                        if (find (xx, yy) == 0)
                        {
                            heap[len].x = xx;
                            heap[len].y = yy;
                            heap[len].num = num + 1;
                            len++;
                        }
                        else
                            heap[flag].num = min (num + 1, heap[flag].num);
                    }
            }
        }
        
        std::push_heap (heap, heap + len, cmp);
    }
    
    return -1;
}

int main()
{
    int i, j, k, N, x, y, out;
    char in;
    
    while (scanf ("%d%d", &n, &m) != EOF) {
        memset (map, 'b', sizeof (map) );
        for (i = 0;i <= n + 1;i++)
            for (j = 0;j <= m + 1;j++)
                if (i == 0 || j == 0 || i == n + 1 || j == m + 1)
                    map[i][j] = 'B';
                    
        scanf ("%d%d%d%d", &px, &py, &cx, &cy);
        scanf ("%d", &N);
        p = 0;
        
        while (N--) {
            scanf ("%d %d %c", &x, &y, &in);
            
            if (in != 'B') {
                p++;
                que[p].x = x;
                que[p].y = y;
                que[p].dic = in;
            }
            else
                map[x][y] = 'B';
        }
        
        makemap();
        
        out = BFS();
        printf ("%d\n", out);
    }
    
    return 0;
}

