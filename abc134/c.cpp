#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;
  
  vector<int> v(n);
  int max_n = -1, max_n2 = -1;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (max_n < v[i]) {
      max_n = v[i];
    } else if (max_n2 < v[i]) {
      max_n2 = v[i];
    }
  }

  for (auto a : v) {
    if (max_n == a) {
      cout << max_n2 << "\n";
    } else {
      cout << max_n << "\n";
    }
  }
  return 0;
}
