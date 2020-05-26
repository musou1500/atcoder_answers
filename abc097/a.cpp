#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (abs(a - c) <= d) {
    cout << "Yes\n";
    return 0;
  }

  if (abs(a - b) <= d && abs(b - c) <= d) {
    cout << "Yes\n";
    return 0;
  }

  cout << "No\n";
  return 0;
}

