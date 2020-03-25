#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
  int n, k;
  cin >> n >> k;

  int cnt = 0;
  while (n > 0) {
    cnt++;
    n /= k;
  }

  cout << cnt << "\n";
}
