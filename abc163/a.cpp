#include <iomanip>
#include <ios>
#include <iostream>

using namespace std;
const double PI = 3.141592653589;

int main(int argc, const char *argv[]) {
  //
  double r;
  cin >> r;
  cout << fixed << setprecision(9) << r * 2 * PI << '\n';
  return 0;
}
