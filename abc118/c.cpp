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
  int n;
  cin >> n;
  vector<long long> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  int ans = va.front();
  for (int i = 0; i < n; ++i) {
    ans = gcd(ans, va[i]);
  }

  cout << ans << '\n';
  return 0;
}
