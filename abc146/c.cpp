#include <iostream>
#include <array>

using namespace std;

int count_digits(long long n) {
  int cnt = 0;
  while(n > 0) {
    cnt++;
    n /= 10;
  }

  return cnt;
}

long long calc_price(long long a, long long b, long long n) {
  return a * n + b * count_digits(n);
}

int main(int argc, const char *argv[])
{
  long long a, b, x;
  cin >> a >> b >> x;

  long long left = 0, right = 1000000000, mid;
  long long max_int = 0;
  while (left <= right) {
    mid = (left + right) / 2;
    long long price = calc_price(a, b, mid);
    long long next_price = calc_price(a, b, mid + 1);
    if (price <= x && (mid == right || next_price > x)) {
      max_int = mid;
      break;
    }

    if (x > price) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  
  cout << max_int << "\n";
  return 0;
}
