#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  int k, n;
  cin >> k >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int max_dist = a[1] - a[0], sum = max_dist;
  for (int i = 2; i < n; i++) {
    sum += a[i] - a[i - 1];
    max_dist = max(max_dist, a[i] - a[i - 1]);
  }

  sum += a[0] + (k - a[n - 1]);
  max_dist = max(max_dist, a[0] + (k - a[n - 1]));

  cout << sum - max_dist << "\n";

  return 0;
}
