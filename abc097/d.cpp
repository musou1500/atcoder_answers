#include <cstddef>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

class UnionFind {
  vector<int> par;

 public:
  UnionFind(size_t N) : par(N) {
    for (size_t i = 0; i < N; i++) {
      par[i] = i;
    }
  };

  int root(int x) {
    if (par[x] == x) {
      return x;
    }

    par[x] = root(par[x]);
    return par[x];
  }

  void unite(int x, int y) {
    int rx = root(x);
    int ry = root(y);
    if (rx == ry) {
      return;
    }

    par[rx] = ry;
  }

  bool same(int x, int y) { return root(x) == root(y); }
};

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  UnionFind tree(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    tree.unite(x - 1, y - 1);
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (tree.same(nums[i] - 1, i)) {
      cnt++;
    }
  }

  cout << cnt << "\n";
  return 0;
}

