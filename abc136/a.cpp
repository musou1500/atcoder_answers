#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
  int a, b, c;
  cin >> a >> b >> c;
  int ans = max(0, c - a + b);
  cout << ans << "\n";
  return 0;
}
