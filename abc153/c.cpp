#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[])
{
  long long n, k;
  cin >> n >> k;
  vector<long> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }

  sort(h.begin(), h.end(), greater<long long>());
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (i >= k) {
      ans += h[i];
    }
  }

  cout << ans << "\n";
  return 0;
}
