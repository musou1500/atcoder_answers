#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
  long long w, h, x, y;
  cin >> w >> h >> x >> y;
  cout << w * h / 2.0 << " ";
  cout << (x * 2 == w && y * 2 == h ? 1 : 0) << "\n";
  return 0;
}
