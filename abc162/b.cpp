#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
  long long n, ans = 0;
  cin >> n;

  for (long long i = 1; i <= n; i++) {
    if (i % 3 == 0 || i % 5 == 0) {
      continue;
    }

    ans += i;
  }

  cout << ans << "\n";

  return 0;
}
