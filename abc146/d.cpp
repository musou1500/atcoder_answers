#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <algorithm>

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
  int n;
  cin >> n;
  vector<set<int>> vertices(n);
  for (int i = 0; i < n - 1; i++) {
    int src, dest;
    cin >> src >> dest;
    vertices[src].insert(dest);
    vertices[dest].insert(src);
  }
  
  // 辺数の最大値を求める
  decltype(vertices)::iterator max_vertix_it, it;
  int max_vertix = 0, i;
  for (it = vertices.begin(), i = 0; it != vertices.end(); it++, i++) {
    if (max_vertix_it->size() < it->size()) {
      max_vertix_it = it;
      max_vertix = i;
    }
  }

  cout << max_vertix_it->size() << "\n";

  // 色を決定する
  // 色の数だけUnion-Find木を持っておく
  vector<UnionFind> ufs(max_vertix_it->size());
  
  
}
