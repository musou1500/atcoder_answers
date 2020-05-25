#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b;
  cin >> a >> b;
  int cnt = 0;
  for (int i = 1; i <= a; ++i) {
    if (i < a) {
      cnt++;
      continue;
    }

    if (i <= b) {
      cnt++;
      continue;
    }
  }

  cout << cnt << '\n';
  return 0;
}
