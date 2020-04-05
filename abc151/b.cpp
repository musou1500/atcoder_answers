#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
  int n, k, m;
  cin >> n >> k >> m;
  int sum = 0;
  for (int i = 0; i < n - 1; i++) {
    int a;
    cin >> a;
    sum += a;
  }

  int ans = max(0, m * n - sum);
  if (ans > k) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
  
  return 0;
}
