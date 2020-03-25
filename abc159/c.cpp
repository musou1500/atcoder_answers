#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, const char *argv[])
{
  double l;
  cin >> l;
  l /= 3;
  cout << setprecision(9) << fixed << (l * l * l) << "\n";
  return 0;
}
