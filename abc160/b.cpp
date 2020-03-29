#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
  int x;
  cin >> x;

  int cnt500 = x / 500;
  x = x % 500;
  int cnt5 = x / 5;

  cout << cnt500 * 1000 + cnt5 * 5 << "\n";
  
  return 0;
}
