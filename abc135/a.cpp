#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
  int a, b;
  cin >> a >> b;
  if (a > b) {
    swap(a, b);
  }

  // aのほうが小さい
  if ((b - a) % 2 == 1) {
    cout << "IMPOSSIBLE\n";
  } else {
    cout << (b - (b - a) / 2) << "\n";
  }
  
  return 0;
}
