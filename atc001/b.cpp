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
  int n, q;
  cin >> n >> q;
  UnionFind tree(n);
  for (int i = 0; i < q; i++) {
    int p, x, y;
    cin >> p >> x >> y;
    if (p == 0) {
      tree.unite(x, y);
    } else {
      cout << (tree.same(x, y) ? "Yes\n" : "No\n");
    }
  }
  return 0;
}

