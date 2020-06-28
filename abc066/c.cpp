#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<ll> va(n);

  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  deque<ll> ans;
  for (int i = 0; i < va.size(); ++i) {
    if (i % 2 == 0) {
      ans.push_back(va[i]);
    } else {
      ans.push_front(va[i]);
    }
  }

  bool rev = n % 2 != 0;
  if (rev) {
    for (auto it = ans.rbegin(); it != ans.rend(); it++) {
      cout << *it;
      if (it == ans.rend() - 1) {
        cout << '\n';
      } else {
        cout << ' ';
      }
    }
  } else {
    for (auto it = ans.begin(); it != ans.end(); it++) {
      cout << *it;
      if (it == ans.end() - 1) {
        cout << '\n';
      } else {
        cout << ' ';
      }
    }
  }

  return 0;
}
