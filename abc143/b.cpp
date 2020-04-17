#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<int> vd(n);
  for (int i = 0; i < n; i++) {
    cin >> vd[i];
  }

  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      ans += vd[i] * vd[j];
    }
  }

  cout << ans << '\n';

  return 0;
}
