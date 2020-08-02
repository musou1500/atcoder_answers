#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BIT {
  vector<T> tree_;

 public:
  BIT(int n) : tree_(n, 0) {}
  void Add(int i, T x) {
    for (i++; i <= tree_.size(); i += i & -i) {
      tree_[i - 1] += x;
    }
  }

  T Sum(int s) {
    T ans = 0;
    for (s++; s > 0; s -= s & -s) {
      ans += tree_[s - 1];
    }

    return ans;
  }

  T Sum(int l, int r) { return Sum(r) - Sum(l - 1); }
};

int main(int argc, const char *argv[]) {
  int n, q;
  cin >> n >> q;

  vector<int> vc(n);
  for (int i = 0; i < n; ++i) {
    cin >> vc[i];
    vc[i]--;
  }

  vector<array<int, 3>> vq(q);
  for (int i = 0; i < q; ++i) {
    int l, r;
    cin >> l >> r;
    vq[i][0] = r - 1;
    vq[i][1] = l - 1;
    vq[i][2] = i;
  }

  sort(vq.begin(), vq.end());

  BIT<int> bit(n);
  vector<int> vp(n, -1), ans(q);
  int prev = 0;
  for (auto &q : vq) {
    int l, r, idx;
    r = q[0];
    l = q[1];
    idx = q[2];
    for (int i = prev; i <= r; ++i) {
      int c = vc[i];
      if (vp[c] < i) {
        if (vp[c] != -1) {
          bit.Add(vp[c], -1);
        }

        bit.Add(i, 1);
        vp[c] = i;
      }

      ans[idx] = bit.Sum(l, r);
    }

    prev = r;
  }

  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << '\n';
  }
  return 0;
}
