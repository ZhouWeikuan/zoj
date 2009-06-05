#include<complex>
#include<iostream>
#include<string.h>
using namespace std;
// complement B with all zeros, and then calculate the convultion with A
enum {
    LIM = 512,
};

typedef complex<double> val_t;

const val_t I = val_t(0, 1);
const double PI = asin(1.0)*2;
const double eps = 1e-7;

int M, N, P, Q;
int A[LIM][LIM], B[LIM][LIM], S[LIM][LIM];
val_t tab[3][LIM*LIM*2];

int rev(int i, int n){
    int d = 0;
    for(int sz=1; sz<n; sz<<=1)
    {
        d<<=1;
        if(i&sz){
            d |= 1;
        }
    }
    return d;
}

void bit_reverse_copy(val_t *s, val_t *d, int n)
{
    for(int i=0; i<n; i++){
        d[rev(i, n)] = s[i];
    }
}

val_t * iterative_fft(val_t *a, val_t *A, int n)
{
    bit_reverse_copy(a, A, n);

    val_t wm = exp(PI*I);
    for(int m=1; m<n; m<<=1){
        for(int k=0; k<n; k+=2*m){
            val_t w = 1.0;
            for(int j=0; j<m; j++){
                val_t t = w*A[k+j+m];
                A[k+j+m] = A[k+j] - t;
                A[k+j] += t;
                w *= wm;
            }
        }
        wm = sqrt(wm);
    }
    return A;
}

val_t * iterative_inverse_fft(val_t *a, val_t *A, int n)
{
    bit_reverse_copy(a, A, n);

    val_t wm = exp(-PI*I);
    for(int m=1; m<n; m<<=1){
        for(int k=0; k<n; k+=2*m){
            val_t w = 1.0;
            for(int j=0; j<m; j++){
                val_t t = w*A[k+j+m];
                A[k+j+m] = A[k+j] - t;
                A[k+j] += t;
                w *= wm;
            }
        }
        wm = sqrt(wm);
    }

    return A;
}

void process()
{
    int i, j, n = 0;
    int siz;
    val_t *x = tab[0], *y = tab[1], *t = tab[2];

    memset(tab, 0, sizeof(tab));
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            x[n].real() = A[i][j];
            if (i < P && j < Q){
                y[n].real() = B[i][j];
            }
            n++;
        }
    }

    for(siz=1; siz<n; siz<<=1)
        ;
    n = siz;
    t[0] = y[0];
    for(i=1; i<n; i++){
        t[i] = y[n-i];
    }
    
    y = iterative_fft(x, y, siz);
    x = iterative_fft(t, x, siz);
    for(i=0; i<siz; i++){
        y[i] *= x[i];
    }

    x = iterative_inverse_fft(y, x, siz);
    for(int i=0; i<siz; i++){
        x[i] /= siz;
    }
    
    int si=0, sj=0;
    double val = 1e100, tmp;
    for(i=0; i<M-P+1; i++){
        for(j=0; j<N-Q+1; j++){
            tmp = S[i][j] - 2 * x[i*N+j].real();
            if (tmp < val){
                si = i, sj = j;
                val = tmp;
            }
        }
    }
    printf("%d %d\n", si+1, sj+1);
}

void calcSum()
{
    int i, j;
    for(i=0; i<M; i++){
        B[i][0] = 0;
        for(j=0;j<Q; j++){
            B[i][0] += A[i][j] * A[i][j];
        }
        for(j=Q; j<N; j++){
            B[i][j-Q+1] = B[i][j-Q] - A[i][j-Q] * A[i][j-Q] + A[i][j]*A[i][j];
        }
    }
    for(j=0; j<N; j++){
        S[0][j] = 0;
        for(i=0; i<P; i++){
            S[0][j] += B[i][j];
        }
        for(i=P; i<M; i++){
            S[i-P+1][j] = S[i-P][j] - B[i-P][j] + B[i][j];
        }
    }
}

void readIn(){
    scanf("%d%d%d%d ", &M, &N, &P, &Q);
    int i, j;
    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            scanf("%d ", &A[i][j]);
        }
    }
    calcSum();
    for(i=0; i<P; i++){
        for(j=0; j<Q; j++){
            scanf("%d ", &B[i][j]);
        }
    }
}

int main() 
{
    int tstnum;
    scanf("%d ", &tstnum);
    while(tstnum --){
        readIn();
        process();
    }
    return 0;
}

