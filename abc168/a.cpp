#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  n = n % 10;
  if (n == 3) {
    cout << "bon" << '\n';
  } else if (n == 0 || n == 1 || n == 6 || n == 8) {
    cout << "pon" << '\n';
  } else {
    cout << "hon" << '\n';
  }
  return 0;
}
