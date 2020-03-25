#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

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

  bool Same(int key1, int key2) {
    return Root(key1) == Root(key2);
  }
  
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

int main(int argc, const char *argv[])
{
  // n 人が登録
  // m 組の友達関係
  // k 組のブロック関係
  int n, m, k;
  cin >> n >> m >> k;

  vector<set<int>> blocks(n);
  vector<set<int>> friends(n);
  UnionFind uf;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    friends[a].insert(b);
    friends[b].insert(a);
    uf.Unite(a, b);
  }

  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (uf.Same(a, b)) {
      blocks[a].insert(b);
      blocks[b].insert(a);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << uf.Size(i) - blocks[i].size() - friends[i].size() - 1
      << (i == n - 1 ? "\n" : " ");
  }

  return 0;
}
