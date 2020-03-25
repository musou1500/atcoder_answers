#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
  int n, d;
  cin >> n >> d;

  int ans = (n - 1) / (d * 2 + 1) + 1;
  cout << ans << "\n";
  return 0;
}
