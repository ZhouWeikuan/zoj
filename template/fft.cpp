#include<complex>
#include<iostream>
using namespace std;

typedef complex<double> val_t;

const val_t I = val_t(0, 1);
const double PI = asin(1.0)*2;

val_t * recursive_fft(val_t *a, val_t *t, int n)
{
    if (n <= 1){
        return a;
    }
    int k, s = n/2;
    const val_t wn = exp(2*PI/n * I);
    val_t w = 1.0;

    for(k=0; k<n; k+=2){
        t[k/2] = a[k];
    }
    for(k=1; k<n; k+=2){
        t[s + k/2] = a[k];
    }
    
    val_t *y0 = recursive_fft(t, a, s);
    val_t *y1 = recursive_fft(t+s, a+s, s);

    for (k=0; k<s; ++k){
        a[k] = y0[k] + w*y1[k];
        a[k+s] = y0[k] - w*y1[k];
        w *= wn;
    }

    return a;
}

val_t * inverse_fft(val_t *a, val_t *t, int n)
{
    if (n <= 1){
        return a;
    }
    int k, s = n/2;
    const val_t wn = exp(-2*PI/n * I);
    val_t w = 1.0;

    for(k=0; k<n; k+=2){
        t[k/2] = a[k];
    }
    for(k=1; k<n; k+=2){
        t[s + k/2] = a[k];
    }
    
    val_t *y0 = inverse_fft(t, a, s);
    val_t *y1 = inverse_fft(t+s, a+s, s);

    for (k=0; k<s; ++k){
        a[k] = y0[k] + w*y1[k];
        a[k+s] = y0[k] - w*y1[k];
        w *= wn;
    }

    return a;
}

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

int main() 
{
    int siz, n;
    double v;
    val_t a[100] = {0};
    val_t b[100] = {0};
    val_t t[100] = {0};
    val_t *x, *y;

    scanf("%d ", &n);
    for(int i=0; i<n; i++){
        scanf("%lf", &v);
        a[i].real() = v;
        a[i].imag() = 0;
    }
    for(int i=0; i<n; i++){
        scanf("%lf", &v);
        b[i].real() = v;
        b[i].imag() = 0;
    }
    for(siz=1; siz<n; siz<<=1)
        ;
    siz<<=1;
    
    x = iterative_fft(a, t, siz);
    y = iterative_fft(b, a, siz);
    for(int i=0; i<siz; i++){
        y[i] *= x[i];
    }

    x = iterative_inverse_fft(y, x, siz);
    for(int i=0; i<siz; i++){
        x[i] /= siz;
        if (fabs(x[i].imag()) < 1e-7){
            x[i].imag() = 0;
        }
        if (fabs(x[i].real()) < 1e-7){
            x[i].real() = 0;
        }
        cout<< x[i] << " ";
    }
    cout<<endl;

    return 0;
}

