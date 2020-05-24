#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<string> ws(n);
  for (int i = 0; i < n; ++i) {
    cin >> ws[i];
  }

  bool ans = true;
  for (int i = 1; i < n; ++i) {
    if (ws[i - 1].back() != ws[i].front()) {
      ans = false;
      break;
    }

    auto w_it = find(ws.begin(), ws.begin() + i, ws[i]);
    if (w_it != ws.begin() + i) {
      ans = false;
      break;
    }
  }

  cout << (ans ? "Yes" : "No") << '\n';

  return 0;
}
