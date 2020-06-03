#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b;
  cin >> a >> b;
  cout << max({a + b, a - b, a * b}) << '\n';
  return 0;
}
