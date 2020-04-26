#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int i = 0;
  while (a > 0 && c > 0) {
    if (i % 2 == 0) {
      c -= b;
    } else {
      a -= d;
    }
    i++;
  }

  if (a > 0) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
