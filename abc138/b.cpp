#include <ios>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  double sum_inv = 0;
  for (auto n : a) {
    sum_inv += 1. / n; 
  }

  cout << fixed << setprecision(9) << 1. / sum_inv << "\n";
  return 0;
}
