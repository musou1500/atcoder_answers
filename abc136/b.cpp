#include <iostream>
#include <cmath>

using namespace std;

int count_digit(int n) {
  int cnt = 0;
  while (n != 0) {
    n /= 10;
    cnt++;
  }

  return cnt;
}

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;

  int digit_cnt = count_digit(n);
  int ans = 0;
  for (int i = 1; i < digit_cnt; i++) {
    if (i % 2 == 1) {
      ans += pow(10, i) - pow(10, i - 1);
    }
  }

  if (digit_cnt % 2 == 1) {
    ans += n - static_cast<int>(pow(10, digit_cnt - 1)) + 1;
  }

  cout << ans << "\n";
  return 0;
}
