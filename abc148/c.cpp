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

template <class M, class N>
common_type_t<M, N> lcm(M a, N b) {
  return a * b / gcd(a, b);
}

int main(int argc, const char *argv[]) {
  long long a, b;
  cin >> a >> b;
  cout << lcm(a, b) << '\n';
  return 0;
}
