#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;

using ll = long long;
ll solve(vector<vector<int>> &tree, int k, int cur = 0, int p = -1) {
  ll ans = 1, base = k - (p != -1);

  for (int i = 0, nth = 1; i < tree[cur].size(); ++i, ++nth) {
    if (tree[cur][i] == p) {
      nth--;
      continue;
    }

    ans = ans * (base - nth) % md;
    ans = ans * solve(tree, k, tree[cur][i], cur) % md;
  }

  return ans;
}

int main(int argc, const char *argv[]) {
  int n, k;
  cin >> n >> k;

  vector<vector<int>> tree(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  cout << solve(tree, k) * k % md << '\n';
  return 0;
}

