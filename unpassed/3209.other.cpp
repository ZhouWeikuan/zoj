#include <iostream>
#include <cstring>
using namespace std;

#define sz 451451

int l[sz], r[sz], u[sz], d[sz], y[sz];
int s[961];

int n, m, ret;

inline void remove(const int &c) {
    int i, j;
    r[l[c]] = r[c];
    l[r[c]] = l[c];
    for(i = d[c]; i != c; i = d[i]) {
        for(j = r[i]; j != i; j = r[j]) {
            d[u[j]] = d[j];
            u[d[j]] = u[j];
            s[y[j]] --;
        }
    }
}

void resume(const int &c) {
    int i, j;
    for(i = u[c]; i != c; i = u[i]) {
        for(j = l[i]; j != i; j = l[j]) {
            d[u[j]] = j;
            u[d[j]] = j;
            s[y[j]] ++;
        }
    }
    r[l[c]] = c;
    l[r[c]] = c;
}

int dfs(int k) {
    if(ret <= k)
        return 0;

    int i, j, c;
    if(r[0] == 0) {
        if(k < ret)
            ret = k;
        return 1;
    }
    int mi = 0x7FFFFFFF;
    for(i = r[0]; i; i = r[i]) {
        if(s[i] < mi) {
            mi = s[i];
            c = i;
        }
    }

    remove(c);
    for(i = d[c]; i != c; i = d[i]) {
        for(j = r[i]; j != i; j = r[j]) {
            remove(y[j]);
        }

        dfs(k + 1);

        for(j = l[i]; j != i; j = l[j]) {
            resume(y[j]);
        }
    }
    resume(c);

    return 0;
}

int main()
{
    int t, tn, tm, t1, t2, pos;
    int i, j, k;
    int x1, y1, x2, y2;
    scanf("%d", &t);

    while(t --) {
        scanf("%d %d %d", &tn, &tm, &n);
        m = tn * tm;
        for(i = 0; i <= m; i++) {
            if(i + 1 > m)
                t1 = 0;
            else
                t1 = i + 1;
            r[i] = t1, l[t1] = i;
            u[i] = i;
            s[i] = 0;
        }

        int hd;
        t2 = m + 1;

        for(i = 1; i <= n; i++) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            hd = t2;
            x2 --, y2 --;
            for(j = y1; j <= y2; j++) {
                pos = j * tn + x1 + 1;
                for(k = x1; k <= x2; k++) {
                    t1 = t2;
                    if(j == y2 && k == x2)
                        t2 = hd;
                    else
                        t2 ++;
                    u[t1] = u[pos], d[u[t1]] = t1;
                    u[pos] = t1, s[pos] ++;
                    r[t1] = t2, l[t2] = t1;
                    y[t1] = pos;
                    pos++;
                }
            }
            t2 = t1 + 1;
        }

        bool fg = 1;

        for(j = 1; j <= m; j++) { 
            if(!s[j]) {
                fg = 0;
                break;
            }
            d[u[j]] = j;
        }

        if(!fg)
            printf("-1\n");
        else {
            ret = 0x7FFFFFFF;
            dfs(0);
            if(ret == 0x7FFFFFFF)
                printf("-1\n");
            else
                printf("%d\n", ret);
        }
    }
    return 0;
}

