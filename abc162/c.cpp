#include <iostream>

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
  int k, ans = 0;
  cin >> k;

  for (int a = 1; a <= k; a++) {
    for (int b = 1; b <= k; b++) {
      for (int c = 1; c <= k; c++) {
        ans += gcd(gcd(a, b), c);
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
