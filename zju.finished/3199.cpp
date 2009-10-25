#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
enum {
    SIZ = 50004,
    ALP = 256,
};

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

int main(){
    /* 
    scanf("%s %s", buf, b2);
    int t = getMaximumCommonSubString(buf, b2);
    printf("%d\n", t);
    */
    int tn;
    scanf("%d ", &tn);
    while(tn--){
        gets(buf);
        printf("%d\n", get_clrs(buf));
    }
    return 0;
}

