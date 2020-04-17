#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b;
  cin >> a >> b;
  if (a < 10 && b < 10) {
    cout << a * b << '\n';
  } else {
    cout << -1 << '\n';
  }
  return 0;
}
