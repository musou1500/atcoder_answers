#include <algorithm>
#include <functional>
#include <ios>
#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

using namespace std;

int main(int argc, const char *argv[])
{
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end(), greater<int>());
  int sum = accumulate(a.begin(), a.end(), 0);
  double threshold = sum / (4. * m);
  bool ans = true;
  for (int i = 0; i < m; i++) {
    if (a[i] < threshold) {
      ans = false;
      break;
    }
  }

  cout << (ans ? "Yes" : "No") << "\n";
  
  return 0;
}
