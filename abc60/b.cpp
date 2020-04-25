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
  //
  int a, b, c;
  cin >> a >> b >> c;
  bool ans = c % gcd(a, b) == 0;
  cout << (ans ? "YES" : "NO") << '\n';
  return 0;
}
