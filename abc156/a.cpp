#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
  // 参加回数, 表示レーティング
  int n, r;
  cin >> n >> r;
  if (n >= 10) {
    cout << r << "\n";
  } else {
    // r = internal - (100*10 - k)
    cout << r + 100* (10 - n) << "\n";
  }

  return 0;
}
