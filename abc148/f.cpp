#include <iostream>
#include <vector>

using namespace std;

using Tree = vector<vector<int>>;

void dfs(Tree &tree, int v, vector<int> &results, int p = -1, int dist = 0) {
  results[v] = dist;
  for (auto neighbor : tree[v]) {
    if (neighbor != p) {
      dfs(tree, neighbor, results, v, dist + 1);
    }
  }
}

int main(int argc, const char *argv[]) {
  int n, u, v;
  cin >> n >> u >> v;
  u--;
  v--;

  Tree tree(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }

  vector<int> u_dists(n), v_dists(n);
  dfs(tree, u, u_dists);
  dfs(tree, v, v_dists);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (u_dists[i] < v_dists[i]) {
      ans = max(ans, v_dists[i]);
    }
  }

  cout << ans - 1 << '\n';
  return 0;
}
