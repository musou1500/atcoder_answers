// まだ解けてない

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int solve(vector<set<int>> &graph, int n, int p) {
  if (graph[n].size() == 0) {
    return 1;
  }

  int ans = 0;
  for (auto g : graph[n]) {
    ans += graph[n].size() * solve(graph, g, p);
  }

  return ans;
}

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;

  vector<set<int>> graph(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b) {
      swap(a, b);
    }

    graph[a].insert(b);
  }

  cout << "input compl\n";

  for (int i = 0; i < n; i++) {
    cout << solve(graph, i) << "\n";
  }
  
  return 0;
}
