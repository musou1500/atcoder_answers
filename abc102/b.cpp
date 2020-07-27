#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<int> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  sort(va.begin(), va.end());
  cout << va.back() - va.front() << '\n';

  return 0;
}
