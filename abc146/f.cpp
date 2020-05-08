#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  string s;
  cin >> n >> m >> s;

  vector<int> ans;
  int cur = s.size() - 1;
  while (cur > 0) {
    int dist = min(m, cur);
    while (dist > 0 && s[cur - dist] == '1') {
      dist--;
    }

    if (dist == 0) {
      cout << -1 << '\n';
      return 0;
    }

    ans.push_back(dist);
    cur -= dist;
  }

  for (auto it = ans.rbegin(); it != ans.rend(); it++) {
    int dist = distance(it, ans.rend());
    cout << *it << (dist > 1 ? ' ' : '\n');
  }
  return 0;
}
