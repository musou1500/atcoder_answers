#include <bits/stdc++.h>

using namespace std;

#include <unordered_map>

using std::unordered_map;

class UnionFind {
  // unordered_map<int, int> graph_;
  // unordered_map<int, int> sizes_;
  vector<int> graph_;
  vector<int> sizes_;

 public:
  UnionFind(int n) : sizes_(n, 1), graph_(n) {
    for (int i = 0; i < n; ++i) {
      graph_[i] = i;
    }
  };

  int Root(int key) {
    if (graph_[key] == key) {
      return key;
    } else {
      return graph_[key] = Root(graph_[key]);
    }
  }

  bool Same(int key1, int key2) { return Root(key1) == Root(key2); }

  void Unite(int key1, int key2) {
    if (Same(key1, key2)) {
      return;
    }

    int root1 = Root(key1);
    int root2 = Root(key2);
    int size = Size(root1) + Size(root2);
    graph_[root1] = root2;
    sizes_[root2] = size;
  }

  int Size(int key) {
    int root = Root(key);
    return sizes_[root];
  }
};

int main(int argc, const char *argv[]) {
  //
  int n, m;
  cin >> n >> m;

  UnionFind uf(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    uf.Unite(a, b);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, uf.Size(i));
  }

  cout << ans << '\n';
  return 0;
}
