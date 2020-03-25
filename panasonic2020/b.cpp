#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
  long long h, w;
  cin >> h >> w;

  if (w == 1 || h == 1) {
    cout << 1 << "\n";
    return 0;
  }
  
  long long cnt =  h / 2 * w + h % 2 * ((w + 1) / 2);
  cout << cnt << "\n";
  
  return 0;
}
