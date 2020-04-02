#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;

  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  // 1 2 2 1
  bool ans = true;
  int min_n = h[0] - 1;
  for (int i = 0; i < n - 1; i++) {
    min_n = max(min_n, h[i] - 1);
    if (h[i] <= h[i + 1] || min_n <= h[i + 1]) {
      continue;
    }

    ans = false;
    break;
  }


  cout << (ans ? "Yes" : "No") << "\n";
  return 0;
}

