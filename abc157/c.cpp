#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <cmath>

using namespace std;

int main(int argc, const char *argv[])
{
  int n, m;
  cin >> n >> m;
  vector<int> digits(n, -1);
  bool exists = true;
  for (int i = 0; i < m; i++) {
    int s, c;
    cin >> s >> c;
    int idx = n - s;

    if ((n > 1 && s == 1 && c == 0) || (digits[idx] != -1 && digits[idx] != c)) {
      exists = false;
      break;
    }
    
    digits[idx] = c;
  }
  

  if (!exists) {
    cout << -1 << "\n";
    return 0;
  }

  if (n > 1 && digits[n - 1] == -1) {
    digits[n - 1] = 1;
  }

  int result = 0;
  for (int i = 0; i < n; i++) {
    result += pow(10, i) * max(digits[i], 0);
  }

  cout << result << "\n";
  return 0;
}
