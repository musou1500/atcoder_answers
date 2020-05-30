#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b;
  cin >> a >> b;
  if (b % a == 0) {
    cout << a + b << '\n';
  } else {
    cout << b - a << '\n';
  }
  return 0;
}
