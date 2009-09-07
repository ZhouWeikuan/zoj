#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
using namespace std;

namespace modular {

const int SIZ = 100;

int primes[SIZ] = {2,3,5,7};
int num = 4;

void init(){
	bool flag;
	for(int n=9; num<SIZ; n+=2){
		flag = true;
		for(int i=0; primes[i]*primes[i]<= n;i++){
			if(n % primes[i] == 0){
				flag = false;
				break;
			}
		}
		if(flag){
			primes[num++] = n;
		}
	}
}

int gcd(int a, int b){
    int t;
    while(b > 0){
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int lcm(const vector<int> &v){
    int r = 1;
    for (int i=0; i<v.size(); ++i){
        r *= v[i]/gcd(r, v[i]);
    }
    return r;
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
    if (d != 1) return 0;
    return x;
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

// chinese reminder theorem
// param 1: cop, co-prime values
// param 2: rem, reminder for each co-prime values
int crt(vector<int> &cop, vector<int> &rem){
    int n = lcm(cop);    
    int v = 0;
    for (int i=0; i<rem.size(); ++i){
        int m = n/cop[i];
        int inv = inverse(m, cop[i]);
        if (inv == 0) return 0;
        v += m * inv * rem[i];
        v %= n;
    }
    v = (v+n)%n;
    return v;
}

// calc a^n(mod m)
int pow(int a, int n, int m){
    int d = a, r = 1;
    while(n > 0){
        if (n &0x01){
            r = (r * d) % m;
        }
        n>>=1;
        d = (d*d)%m;
    }
    return r;
}

bool witness(int a, int n){
    int u = n-1, t = 0;
    while((u&0x01)!=0x01){
        u>>=1;
        ++t;
    }
    int cur, pre = pow(a, u, n);
    while(t--){
        cur = (pre*pre)%n;
        if (cur==1 &&(pre!=1&&pre!=n-1))
            return true;
        pre = cur;
    }
    if (cur !=1) return true;
    return false;
}

// miller-rabin
bool prime_test(int n, int s){
    if (n <= primes[SIZ-1]){
        return binary_search(&primes[0], primes+SIZ, n);
    }
    for(int i=0; i<s; ++i){
        int a = primes[i];
        if (witness(a,n))
            return false;
    }
    return true;
}

// pollard-rho
int factor(int n){
    int i=1;
    int x = 1 + random()%(n-1);
    int y = x;
    int k = 2;
    for(;;){
        ++i;
        x = (x*x-1)%n;
        int d = gcd(y>x?y-x:x-y, n);
        if (d!=1&&d!=n)
            return d;
        if (i==k){
            y = x;
            k <<=1;
        }
    }
    return 0;
}


}// namespace modular

int main(){
    int a,n,m;
    while(scanf("%d", &n) > 0){
        printf("%d\n", modular::factor(n));
    }

    return 0;
}

