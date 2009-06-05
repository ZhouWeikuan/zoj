#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
enum
{
    SIZ = 1004,
};

int N;
double score;
double mat[SIZ];
double rat[12];
double cost[12];
int mask[12];

void fun ()
{
    int cur = (1 << N) - 1, nex;
    queue <int> q;
    memset (mat, 0, sizeof (mat) );
    mat[cur] = score;
    q.push (cur);
    
    while (!q.empty () )
    {
        cur = q.front ();
        q.pop ();
        
        for (int i = 0; i < N; i++)
        {
            if ( (cur & (1 << i) ) == 0)
                continue;
                
            nex = (cur & ~mask[i]) | ( (~cur) & mask[i]);
            
            double v = mat[cur] * cost[i];
            
            if (v > mat[nex])
            {
                mat[nex] = v;
                q.push (nex);
            }
        }
    }
    
    printf ("%.2lf\n", mat[0]);
}

int readIn ()
{
    scanf ("%d%lf ", &N, &score);
    int t, a, m;
    
    for (int i = 0; i < N; i++)
    {
        scanf ("%d ", &t);
        m = 1 << i;
        
        while (t--)
        {
            scanf ("%d ", &a);
            m |= (1 << a);
        }
        
        mask[i] = m;
        
        scanf ("%lf ", &rat[i]);
        rat[i] /= 100;
    }
    
    for (int i = 0; i < N; i++) {
        double v = 1.0;
        
        for (int a = 0, j = 1; j <= mask[i]; a++, j <<= 1) {
            if (j&mask[i])
                v *= rat[a];
        }
        
        cost[i] = v;
    }
    
    return N;
}

int main ()
{

    while (readIn () > 0)
    {
        fun ();
    }
    
    return 0;
}
