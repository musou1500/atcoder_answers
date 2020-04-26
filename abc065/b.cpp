#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<int> va(n);
  for (int i = 0; i < n; i++) {
    cin >> va[i];
    va[i]--;
  }

  int cur = 0, cnt = 0;
  while (cnt < n && cur != 1) {
    cur = va[cur];
    cnt++;
  }

  if (cur == 1) {
    cout << cnt << '\n';
  } else {
    cout << -1 << '\n';
  }

  return 0;
}
