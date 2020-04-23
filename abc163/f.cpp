#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

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
  using ll = long long;
  int n;
  cin >> n;
  vector<vector<int>> vs(n);
  for (int i = 0; i < n; i++) {
    int c;
    cin >> c;
    vs[c - 1].push_back(i);
  }

  vector<vector<int>> tree(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  int k = 0;
  vector<int> in(n), out(n);
  function<void(int, int)> dfs;
  dfs = [&](int v, int p) {
    in[v] = k++;
    for (int u : tree[v]) {
      if (u != p) {
        dfs(u, v);
      }
    }

    out[v] = k - 1;
  };

  dfs(0, -1);

  auto c2 = [](ll n) { return n * (n + 1) / 2; };
  BIT<ll> d(n);
  for (int i = 0; i < n; i++) {
    d.Add(i, 1);
  }

  ll tot = c2(n);
  for (int i = 0; i < n; i++) {
    ll ans = tot;
    vector<int> &nvs = vs[i];
    sort(nvs.begin(), nvs.end(), [&](int a, int b) { return in[a] > in[b]; });
    vector<pair<int, int>> history;
    for (int v : nvs) {
      int cnt = 1;
      for (int u : tree[v]) {
        if (in[u] > in[v]) {
          int num = d.Sum(in[u], out[u]);
          ans -= c2(num);
          cnt += num;
        }
      }

      d.Add(in[v], -cnt);
      history.emplace_back(in[v], cnt);
    }

    ans -= c2(d.Sum(n - 1));
    for (auto p : history) {
      d.Add(p.first, p.second);
    }

    cout << ans << '\n';
  }

  return 0;
}
