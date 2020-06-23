#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<int> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  sort(va.begin(), va.end(), greater<int>());
  int a, b;
  a = b = 0;
  for (int i = 0; i < va.size(); ++i) {
    if (i % 2 == 0) {
      a += va[i];
    } else {
      b += va[i];
    }
  }

  cout << a - b << '\n';
  return 0;
}
