#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, const char *argv[])
{
  long long l, r;
  cin >> l >> r;

  if (r - l > 3000) {
    cout << "0\n";
    return 0;
  }

  long long res = l * (l + 1) % 2019;
  for (long long i = l; i < r; i++) {
    for (long long j = i + 1; j <= r; j++) {
      res = min(res, i * j % 2019);
    }
  }

  cout << res << "\n";
  return 0;
}
