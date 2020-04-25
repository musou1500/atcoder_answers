#include <iomanip>
#include <ios>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
  double n;
  cin >> n;

  int m = static_cast<int>(n) / 2;
  if (static_cast<int>(n) % 2 == 1) {
    m++;
  }

  cout << fixed << setprecision(9) << m / n;
  return 0;
}
