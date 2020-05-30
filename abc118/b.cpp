#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;
  int ans = pow(2, m) - 1;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    int bt = 0;
    for (int i = 0; i < k; ++i) {
      int a;
      cin >> a;
      a--;
      bt |= (1 << a);
    }

    ans &= bt;
  }

  cout << bitset<32>(ans).count() << '\n';
  return 0;
}
