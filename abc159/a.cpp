#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
  int n, m;
  cin  >> n >> m;

  int ans = m * (m - 1) / 2;
  ans += n * (n - 1) / 2;
  cout << ans << "\n";
  return 0;
}
