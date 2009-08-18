/*
 ******************************************************
 ZOJ/ZJU 3224 Mathematics
 Tips 我承认我的代码写的很龊，但是差不多就是这个思路
 把AB区间分成若干部分，再判lcm
 memory 188K
 runtime 140MS
 language C++
 ******************************************************
 */
#include<iostream>
#include<algorithm>
#include<set>
#include<cmath>
using namespace std;
set<int> se;
int mat[1001];
int MAX, N, A, B;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    if (a > b) return (a * b) / gcd(a, b);
    else return (a * b) / gcd(b, a);
}

int ToLog(int a, int b) {
    int ret = 0;
    while (a) {
        a /= b;
        ret++;
    }
    return --ret;
}

int ToLcm(int k) {
    int ret = 1;
    for (int i = 0; i < N; i++) {
        int tmp = ToLog(k, mat[i]);
        ret = lcm(ret, tmp);
        if (tmp <= 2) {
            break;
        }
    }
    return ret;
}

int solve() {
    int ret = 0;
    set<int>::iterator p, q, it;
    q = se.lower_bound(MAX);
    if ((*q) % ToLcm(*q) == 0) ret++;
    ++q;
    int node = 0;
    for (p = q; p != se.end(); p++) {
        node++;
        it = p;
        --it;
        int ll = ToLcm(*it + 1);
        int l = ToLcm(*p);
        ret += ((*p) / l - (*it) / l);
    }
    cout << ret << endl;
    return 0;
}

int main() {
    while (scanf("%d%d%d", &N, &A, &B) != EOF) {
        se.clear();
        se.insert(A), se.insert(B);
        MAX = A;
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            int temp = x;
            mat[i] = x;
            MAX = max(MAX, x);
            for (int j = 0;; j++) {
                if (temp > B) break;
                se.insert(temp);
                if (B / temp >= x) se.insert(temp * x - 1);
                else break;
                temp *= x;
            }
        }
        sort(mat,mat+N);
        if(MAX==B){
            if(B%ToLcm(B)==0) cout<<1<<endl;
            else cout<<0<<endl;
        }else solve();
    }
    return 0;
}

