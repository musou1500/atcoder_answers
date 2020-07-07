#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<int> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  vector<int> cnts(8, 0);
  int other = 0;
  for (int i = 0; i < n; ++i) {
    int a = va[i];
    if (a < 400) {
      cnts[0]++;
    } else if (a < 800) {
      cnts[1]++;
    } else if (a < 1200) {
      cnts[2]++;
    } else if (a < 1600) {
      cnts[3]++;
    } else if (a < 2000) {
      cnts[4]++;
    } else if (a < 2400) {
      cnts[5]++;
    } else if (a < 2800) {
      cnts[6]++;
    } else if (a < 3200) {
      cnts[7]++;
    } else {
      other++;
    }
  }

  int ans_min = 0;
  for (int i = 0; i < cnts.size(); ++i) {
    ans_min += cnts[i] > 0;
  }

  int ans_max = ans_min + other;
  cout << max(1, ans_min) << ' ' << ans_max << '\n';
  return 0;
}
