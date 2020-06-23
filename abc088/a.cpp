#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, a;
  cin >> n >> a;
  bool ans = n % 500 <= a;
  if (ans) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }

  return 0;
}
