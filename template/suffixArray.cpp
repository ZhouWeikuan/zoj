#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
enum {
    SIZ = 50004,
    ALP = 256,
};

namespace O_n {
// the skew algorithm
int c[SIZ];    
inline bool leq(int a1, int a2, int b1, int b2){ // for pairs
    return (a1<b1 || (a1==b1&&a2<=b2));
}

inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3){ // for triples
    return (a1<b1 || (a1==b1&&leq(a2,a3,b2,b3)));
}

// stably sort a[0..n-1] to b[0..n-1] with keys in 0..K from r
void radixPass(int *a, int *b, int *r, int n, int K){
    for (int i=0; i<=K; ++i) c[i] = 0;
    for (int i=0; i<n; ++i) ++c[r[a[i]]];
    for (int i=0, sum=0; i<=K; ++i){
        int t=c[i]; c[i]=sum; sum+=t;
    }
    for (int i=0; i<n; ++i) b[c[r[a[i]]]++] = a[i];
}

void suffixArray(int* T, int* SA, int n, int K){
    int n0=(n+2)/3, n1=(n+1)/3, n2=n/3, n02=n0+n2;
    int* R = new int[n02+3]; R[n02] = R[n02+1] = R[n02+2] = 0;
    int* SA12 = new int[n02+3]; SA12[n02] = SA12[n02+1] = SA12[n02+2] = 0;
    int* R0 = new int[n0];
    int* SA0 = new int[n0];

    for (int i=0, j=0; i<n+(n0-n1); ++i)
        if (i%3!=0) R[j++] = i;
    
    radixPass(R, SA12, T+2, n02, K);
    radixPass(SA12, R, T+1, n02, K);
    radixPass(R, SA12, T  , n02, K);

    int name=0, c0=-1, c1=-1, c2=-1;
    for (int i=0; i<n02; ++i){
        if (T[SA12[i]] !=c0 || T[SA12[i]+1]!=c1 || T[SA12[i]+2] !=c2){
            ++name; c0 = T[SA12[i]]; c1 = T[SA12[i]+1]; c2 = T[SA12[i]+2];
        }
        if (SA12[i]%3==1) { R[SA12[i]/3] = name; }
        else { R[SA12[i]/3 + n0] = name; }
    }

    if (name < n02){
        suffixArray(R, SA12, n02, name);
        for (int i=0; i<n02; ++i)
            R[SA12[i]] = i + 1;
    } else {
        for (int i=0; i<n02; ++i)
            SA12[R[i]-1] = i;
    }

    for (int i=0, j=0; i<n02; ++i) if (SA12[i] < n0) R0[j++] = 3*SA12[i];
    radixPass(R0, SA0, T, n0, K);

    for (int p=0, t=n0-n1, k=0; k < n; ++k){
#define GetI() (SA12[t]<n0?SA12[t]*3+1:(SA12[t]-n0)*3+2)
        int i = GetI();
        int j = SA0[p];

        if (SA12[t] < n0?
                leq(T[i], R[SA12[t]+n0], T[j], R[j/3]):
                leq(T[i], T[i+1], R[SA12[t]-n0+1], T[j], T[j+1], R[j/3+n0])){
            SA[k] = i; ++t;
            if (t==n02)
                for (++k; p<n0; ++p, ++k) SA[k] = SA0[p];
        } else {
            SA[k] = j; ++p;
            if (p==n0)
                for (++k; t<n02; ++t, ++k) SA[k] = GetI();
        }
    }
    delete [] R;
    delete [] SA12;
    delete [] SA0;
    delete [] R0;
}

void calcRank(int* SA, int* Rank, int n){
    for (int i=0; i<n; ++i){
        Rank[SA[i]] = i;
    }
}

void calcHeight(int* H, int* S, int* R, int* str, int n){
    int i, j, k;
    for (k=0, i=0; i<n; ++i){
        if (R[i] == 0){
            H[0] = 0;
        } else {
            for (j=S[R[i]-1]; i+k<n && str[i+k]==str[j+k];++k)
                ;
            H[R[i]] = k;
            if (k > 0)
                --k;
        }
    }
}

}

// use O(nlognlogn) time to construct an suffix array
namespace nlognlogn {
struct suffixArray {
    int tab[2][SIZ];
    int sa[SIZ];
    char *str;
    int len, N;
    int *preRank, *curRank;

    suffixArray(){}
    void set(char *s){
        str = s;
        preRank = tab[0]; curRank = tab[1];
        buildArray();
    }
    void updateRank(){
        int v = 0;
        for (int i=0; i<len; ++i){
            if (i==0||cmp(sa[i-1], sa[i])==0){ // not change
                curRank[sa[i]] = v;
            } else { // change
                curRank[sa[i]] = ++v;
            }
        }
        curRank[len] = -1;
    }

    void buildArray(){    
        for(len=0; str[len]; len++){
            sa[len] = len;        
            preRank[len] = str[len];
        }
        preRank[len] = -1;
        N = 0;
        sort(sa, sa+len, (*this));
        updateRank();
        swap(curRank, preRank);
        N = 1;
        while(N < len){
            sort(sa, sa+len, (*this));
            updateRank();
            swap(curRank, preRank);
            N *= 2;
        }
    }
    bool operator()(int a, int b){
        return cmp(a,b) < 0;
    }
    int cmp(int a, int b){
        if(preRank[a] != preRank[b]){
            return preRank[a] - preRank[b];
        }
        return preRank[a+N] - preRank[b+N];
    }

    void output(bool flag = false){
        if(!flag)
            return ;
        for(int i=0; i<len; i++){
            printf("%s\n", &str[sa[i]]);
        }    
    }
};
}

namespace nlogn {
// website: http://jgshining.cn/blog/post/suffix_array_implemention.php
struct suffixArray {
    int tab[4][SIZ];
    int H[SIZ];
    char *str;
    int *S1, *S2, *R, *B;
    int len;

    suffixArray(){}
    void set(char *s){
        S1 = tab[0];    // suffix array for h string
        S2 = tab[1];    // suffix array for 2h string
        R  = tab[2];    // rank array for h string
        B  = tab[3];    // the index for the bucket tail of free space,and the
                        // rank array for 2h string
        str = s;
        buildArray();
    }
    void buildArray(){
        int i;
        // counting sort when h=1, O(n)
        memset(B, 0, sizeof(tab[0]));
        for (len=0; str[len]; ++len)
            ++B[str[len]];
        for (int i=1; i<ALP; ++i)
            B[i] += B[i-1];
        for (int i=0; i<len; ++i)
            S1[--B[str[i]]] = i;
        // update Rank(1), the same value if the same char
        for (R[S1[0]]=0,i=1; i<len; ++i){
            R[S1[i]] = R[S1[i-1]];
            R[S1[i]] += (str[S1[i]] != str[S1[i-1]]);
        }

        // double increasing sort, log(n) times, each time O(n)
        int h, h2;
        for (h=1; h<len; h<<=1){
            // calc the index for h bucket, the same rank shares the same bucket
            for (i=0; i<len; ++i){
                B[R[S1[i]]] = i;
            }

            // calc 2h bucket from h bucket
            for (i=len-1; i>=0; --i){
                if (h <= S1[i]){
                    S2[B[R[S1[i]-h]]--] = S1[i]-h;
                }
            }
            // calc the left h/2 elements
            for (i=len-h, h2=len-(h>>1); i < h2; ++i){
                S2[B[R[i]]] = i;
            }
            swap(S1, S2);

            // calc Rank(2h)
            for (B[S1[0]]=0, i=1; i<len; ++i){
                if (R[S1[i]] != R[S1[i-1]] ||
                        R[S1[i]+h] != R[S1[i-1]+h])
                {
                    B[S1[i]] = B[S1[i-1]] + 1;
                } else {
                    B[S1[i]] = B[S1[i-1]];
                }
            }
            swap(B, R);
        }
    }
    bool operator()(int a, int b){
        return R[a] < R[b];
    }
    void calcHeight(){
        int i, j, k;
        for (k=0, i=0; i<len; ++i){
            if (R[i] == 0){
                H[0] = 0;
            } else {
                for (j=S2[R[i]-1]; i+k<len && str[i+k]==str[j+k];++k)
                    ;
                H[R[i]] = k;
                if (k > 0)
                    --k;
            }
        }
        /*
        printf("Height array:\n");
        for (i=0; i<len; ++i){
            printf(" %d", H[i]);
        }
        printf("\n");
        */
    }
    void output(bool f=false){
        if(!f) return;
        for (int i=0; i<len; ++i){
            printf("%s\n", &str[S2[i]]);
        }
    }
};

}

// maximum common substring
// we can convert this into k strings' maximum common substring
int getMaximumCommonSubString(char *s1, char *s2){
    int len1 = strlen(s1);
    strcat(s1, ","); // use an unusual value to divide them, to pass "aaa aaaaa"
    strcat(s1, s2);
    nlogn::suffixArray arr;
    arr.set(s1);
    arr.calcHeight();
    int b,i;
    for (b=0,i=1; i<arr.len; ++i){
        if ( (arr.S2[i] < len1 && arr.S2[i-1]>len1) ||
                (arr.S2[i]>len1 && arr.S2[i-1]<len1))
        {
            if (arr.H[i] > b){
                b = arr.H[i];
            }
        }
    }
    return b;
}

// consecutive longest repeated substring
int get_clrs(char *s){
    nlogn::suffixArray arr;
    arr.set(s);
    arr.calcHeight();
    int m=0, a, b;
    for (int i=1; i<arr.len; ++i){
        a = arr.S2[i-1];
        b = arr.S2[i];
        if (a > b) swap(a,b);
        if (arr.H[i] > m && a + arr.H[i] == b){
            m = arr.H[i];
        }
    }
    return m;
}

char buf[SIZ];
int str[SIZ], SA[SIZ], Rank[SIZ];

int main(){
    /* 
    scanf("%s %s", buf, b2);
    int t = getMaximumCommonSubString(buf, b2);
    printf("%d\n", t);
    */
    /*
    int tn;
    scanf("%d ", &tn);
    while(tn--){
        gets(buf);
        printf("%d\n", get_clrs(buf));
    }
    */
    using namespace O_n;
    int N, K=256;
    while(scanf("%s", buf) > 0){
        for (N=0; buf[N]; ++N){
            str[N] = buf[N];
        }
        str[N] = 0; ++N;
        suffixArray(str, SA, N, K);
        for (int i=0; i<N; ++i){
            printf("%s\n", &buf[SA[i]]);
        }
        printf("\n");
    }

    return 0;
}

