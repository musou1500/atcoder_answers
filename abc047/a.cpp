#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b, c;
  cin >> a >> b >> c;
  int total = a + b + c;
  if (total % 2 == 1) {
    cout << "No" << '\n';
    return 0;
  }

  int half = total / 2;
  if (a == half || b == half || c == half) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }

  return 0;
}
