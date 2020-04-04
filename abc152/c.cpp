#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  int ans = 1, min_n = p[0];
  for (int i = 1; i < p.size(); i++) {
    if (p[i] <= min_n) {
      min_n = p[i];
      ans++;
    }
  }

  cout << ans << "\n";
  return 0;
}
