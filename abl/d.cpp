#include <bits/stdc++.h>
#include <atcoder/segtree.hpp>

using namespace std;

int e() { return 0; }
int op(int a, int b) { return max(a, b); };

int main(int argc, const char *argv[]) {
  int n, k;
  cin >> n >> k;

  vector<int> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  int max_n = *max_element(va.begin(), va.end());
  atcoder::segtree<int, op, e> segtree(max_n + 1);
  segtree.set(va.front(), 1);
  for (int i = 1; i < va.size(); ++i) {
    int l = max(0, va[i] - k);
    int r = min(max_n, va[i] + k) + 1;
    int m = segtree.prod(l, r);
    segtree.set(va[i], m + 1);
  }

  cout << segtree.all_prod() << '\n';
  return 0;
}
