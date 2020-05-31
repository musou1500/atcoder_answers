#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, d, x;
  cin >> n >> d >> x;

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    sum += 1 + (d - 1) / a;
  }

  cout << sum + x << '\n';
  return 0;
}
