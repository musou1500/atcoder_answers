#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<int> va(n), vb(n);
  vector<int> a_cnt(n + 1, 0), b_cnt(n + 1, 0);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
    a_cnt[va[i]]++;
  }

  for (int i = 0; i < n; ++i) {
    cin >> vb[i];
    b_cnt[vb[i]]++;
  }

  bool ok = true;
  for (int i = 0; i < n; ++i) {
    int a = va[i];
    int cnt1 = a_cnt[a];
    int cnt2 = n - b_cnt[a];
    if (cnt1 > cnt2) {
      ok = false;
      break;
    }
  }

  if (!ok) {
    cout << "No" << '\n';
    return 0;
  }

  cout << "Yes" << '\n';

  return 0;
}
