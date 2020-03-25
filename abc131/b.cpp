#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
  int n, l;
  cin >> n >> l;
  int sum = n * l + ((1 + n) * n / 2) - n;
  if (l >= 0) {
    cout << sum - l << "\n";
  } else {
    int num = min(abs(l), n - 1);
    cout << sum - (l + num) << "\n";
  }

  return 0;
}
