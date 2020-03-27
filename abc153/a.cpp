#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
  int h, a;
  cin >> h >> a;
  if (h % a == 0) {
    cout << h / a << "\n";
  } else {
    cout << h / a + 1 << "\n";
  }
  return 0;
}
