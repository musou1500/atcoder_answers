#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  using ll = long long;
  int n;
  ll k;
  cin >> n >> k;

  vector<int> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
    va[i]--;
  }

  vector<int> vb;
  vector<int> visited(va.size(), -1);
  int cur = 0, loop_offset = -1;
  while (true) {
    if (visited[cur] != -1) {
      loop_offset = visited[cur];
      break;
    }

    visited[cur] = vb.size();
    vb.push_back(cur);
    cur = va[cur];
  }

  int ans;
  if (k < vb.size()) {
    ans = vb[k];
  } else {
    int idx = (k - vb.size()) % (vb.size() - loop_offset);
    ans = vb[loop_offset + idx];
  }

  cout << ans + 1 << '\n';
  return 0;
}
