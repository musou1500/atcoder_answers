#include <iostream>
#include <vector>
#include <set>

using namespace std;

using ll = long long;

void solve(vector<set<int>> &tree, vector<ll> &cnts, int key = 0, int parent = -1) {
  for (auto child : tree[key]) {
    if (child == parent) {
      continue;
    }

    cnts[child] += cnts[key];
    solve(tree, cnts, child, key);
  }
}

int main(int argc, const char *argv[])
{
  int n, q;
  cin >> n >> q;

  vector<set<int>> tree(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree[a].insert(b);
    tree[b].insert(a);
  }

  vector<ll> cnts(n, 0);
  for (int i = 0; i < q; i++) {
    int p;
    ll x;
    cin >> p >> x;
    p--;
    cnts[p] += x;
  }

  solve(tree, cnts);
  for (int i = 0; i < cnts.size(); i++) {
    cout << cnts[i];
    if (i != n - 1) {
      cout << " ";
    }
  }

  cout << "\n";
  return 0;
}

