#include<iostream>


namespace modular {

int gcd(int a, int b){
    int t;
    while(b > 0){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int egcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    int d = egcd(b, a%b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return d;
}

int inverse(int a, int n){
    int x, y;
    int d = egcd(a, n, x, y);
    if (d != 1) return -1;
    return x;
}

// calc a^b (mod n)
int pow(int a, int b, int n){
    if (b == 0)
        return 1;
    int r = pow(a, b/2, n);
    if (b%2){
        r *= a;
        r %= n;
    }
    return r;
}

// calc  a*x = b (mod n), what is x?
vector<int> linear_equation_solver(int a, int b, int n){
    int x, y;
    int d = egcd(a, n, x, y);
    vector<int> v;
    if (b % d == 0){
        x = (x * b / d) % n;
        for (int i=0; i<d; ++i){
            y = (x + i *(n/d))%n;
            v.push_back(y);
        }
    }
    return v;
}


}// namespace modular
