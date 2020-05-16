#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;
  int cnt_0 = 0, cnt_1 = 0;
  for (auto ch : s) {
    if (ch == '0') {
      cnt_0++;
    } else {
      cnt_1++;
    }
  }

  cout << min(cnt_0, cnt_1) * 2 << '\n';
  return 0;
}
