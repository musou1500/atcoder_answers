#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  int cnt2 = 0, cnt4 = 0, cnt = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a % 4 == 0) {
      cnt4++;
    } else if (a % 2 == 0) {
      cnt2++;
    } else {
      cnt++;
    }
  }

  if (cnt2 > 0) {
    cnt++;
  }

  if ((cnt4 + cnt) % 2 == 0) {
    cout << (cnt4 < cnt ? "No" : "Yes") << '\n';
  } else {
    cout << (cnt4 < cnt - 1 ? "No" : "Yes") << '\n';
  }
  return 0;
}
