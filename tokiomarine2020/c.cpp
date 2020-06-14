#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, op_cnt;
  cin >> n >> op_cnt;
  vector<int> va(n);
  for (auto &a : va) {
    cin >> a;
  }

  for (int i = 0; i < op_cnt; ++i) {
    vector<int> vaa(va.size(), 0);
    for (int j = 0; j < va.size(); ++j) {
      int a = va[j];
      int l_idx = max(0, j - a);
      vaa[l_idx]++;
      int r_idx = j + a + 1;
      if (r_idx < vaa.size()) {
        vaa[r_idx]--;
      }
    }

    va[0] = vaa[0];
    for (int j = 1; j < vaa.size(); ++j) {
      va[j] = va[j - 1] + vaa[j];
    }

    int min_el = *min_element(va.begin(), va.end());
    if (min_el >= n) {
      break;
    }
  }

  for (int j = 0; j < va.size(); ++j) {
    cout << va[j];
    if (j == va.size() - 1) {
      cout << '\n';
    } else {
      cout << ' ';
    }
  }
  return 0;
}
