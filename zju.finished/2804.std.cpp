/* Sample solution to "Funny Games" from NCPC 2005
 * Algorithm: essentially continuous DP, keep track of winning intervals
 * Author: Per Austrin
 */ 
#include <cmath>
#include <cassert>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef pair<double, double> pdd;

template <class It, class OIt>
OIt ival_union(It begin, It end, OIt dest) {
  sort(begin, end);
  while(begin != end) {
    *dest = *begin++;
    while(begin != end && begin->first < dest->second + 1e-8)
      dest->second >?= begin++->second;
    ++dest;
  }
  return dest;
}   

int main(void) {
  int n, k;
  double x, f[10], maxf;
  pdd win[10000], lose;
  for (scanf("%d", &n); n--; ) {
    scanf("%lf%d", &x, &k);
    maxf = lose.second = 0;
    for (int i = 0; i < k; ++i)
      scanf("%lf", f+i), win[i] = make_pair(1, 1 / f[i]), maxf >?= f[i];
    for (int nwin = k, l = 0; x > lose.second; ++l) {
      nwin = ival_union(win + l , win + nwin, win + l) - win;
      lose.second = (lose.first = win[l].second) / maxf;
      if (l < nwin-1) lose.second <?= win[l+1].first;
      for (int i = 0; i < k; ++i)
	win[nwin++] = make_pair(lose.first/f[i], lose.second/f[i]);
    }
    assert(fabs(x-lose.first) > 1e-6 && fabs(x-lose.second) > 1e-6);
    printf("%s\n", x < lose.first ? "Nils" : "Mikael");
  }
}
