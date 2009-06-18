#include<iostream>
#include<cstring>
#include<set>

using namespace std;
enum
{
    SIZ = 1100,
};

int N;
double score;
double mat[SIZ];
double rat[12];
int mask[12];

void fun ()
{
    int cur = (1 << N) - 1, nex;
    set<int> s;
    for (int i=0; i<SIZ; i++)
        mat[i] = -1;
    mat[cur] = score;
    s.insert(cur);
    
    while (!s.empty ()) {
        cur = *s.begin();
        s.erase(cur);
        if (cur == 0)
            continue;
        
        for (int i = 0; i < N; i++) {
            if ((cur &(1<<i)) == 0) continue;
            nex = cur ^ mask[i];
            double v = mat[cur] * rat[i];
            if (v > mat[nex])
            {
                mat[nex] = v;
                s.insert (nex);
            }
        }
    }
    
    if (mat[0] >=0 )
        printf ("%.2lf\n", mat[0]);
    else 
        printf ("-1\n");
}

int readIn () {
    scanf ("%d%lf ", &N, &score);
    int t, a, m;
    
    for (int i = 0; i < N; i++) {
        scanf ("%d ", &t);
        m = 1 << i;
        
        while (t--) {
            scanf ("%d ", &a);
            --a;
            m |= (1 << a);
        }
        
        mask[i] = m;
        
        scanf ("%lf ", &rat[i]);
        rat[i] = (100 - rat[i])/100.0;
    }

    return !(N==0&&score==0.0);
}

int main () {

    while (readIn () > 0) {
        fun ();
    }
    
    return 0;
}

