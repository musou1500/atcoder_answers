#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
  long long n, a, b;
  cin >> n >> a >> b;
  if (a == 0 && b == 0) {
    cout << 0 << "\n";
  } else {
    long long d = n / (a + b);
    long long e = min(n % (a + b), a);
    cout << d * a + e << "\n";
  }
}
