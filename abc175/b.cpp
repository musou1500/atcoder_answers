#include <bits/stdc++.h>
#include <vector>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<ll> vl(n);
  for (int i = 0; i < n; ++i) {
    cin >> vl[i];
  }

  int cnt = 0;
  for (int i = 0; i < n - 2; ++i) {
    for (int j = i + 1; j < n - 1; ++j) {
      for (int k = j + 1; k < n; ++k) {
        int a = vl[i], b = vl[j], c = vl[k];
        if (a == b || b == c || a == c) {
          continue;
        }

        if (a + b > c && b + c > a && c + a > b) {
          cnt++;
        }
      }
    }
  }

  cout << cnt << '\n';
  return 0;
}
