#include <bits/stdc++.h>

using namespace std;

template <class M, class N>
common_type_t<M, N> gcd(M a, N b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}

int main(int argc, const char *argv[]) {
  int n, x;
  cin >> n >> x;

  vector<int> vx(n);
  for (int i = 0; i < n; ++i) {
    cin >> vx[i];
  }

  int ans = abs(x - vx.front());
  for (int i = 1; i < n; ++i) {
    ans = gcd(ans, abs(x - vx[i]));
  }

  cout << ans << '\n';
  return 0;
}
