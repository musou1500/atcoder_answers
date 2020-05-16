#include <bits/stdc++.h>
#include <algorithm>
#include <utility>

using namespace std;

#include <unordered_map>

using std::unordered_map;

class UnionFind {
  unordered_map<int, int> graph_;
  unordered_map<int, int> sizes_;

 public:
  int Root(int key) {
    if (graph_.count(key) == 0 || graph_[key] == key) {
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
    return sizes_.count(root) > 0 ? sizes_[root] : 1;
  }
};

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edges[i] = make_pair(a, b);
  }

  auto c2 = [](long long n) -> long long { return n * (n - 1ll) / 2ll; };
  UnionFind uf;
  vector<long long> ans{c2(n)};

  for (int i = m - 1; i >= 1; --i) {
    auto edge = edges[i];
    if (uf.Same(edge.first, edge.second)) {
      ans.push_back(ans.back());
    } else {
      long long sz1 = uf.Size(edge.first), sz2 = uf.Size(edge.second);
      ans.push_back(ans.back() - sz1 * sz2);
    }

    uf.Unite(edge.first, edge.second);
  }

  reverse(ans.begin(), ans.end());
  for (auto a : ans) {
    cout << a << '\n';
  }

  return 0;
}
