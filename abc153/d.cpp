#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
  unsigned long long h;
  cin >> h;

  unsigned long long cnt = 0;
  while (h != 0) {
    h /= 2;
    cnt++;
  }

  unsigned long long pow2 = 1;
  unsigned long long ans = 0;
  for (int i = 0; i < cnt; i++) {
    ans += pow2;
    pow2 *= 2;
  }
  

  cout << ans << "\n";
  return 0;
}
