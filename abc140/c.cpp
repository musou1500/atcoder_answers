#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<int> vb(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> vb[i];
  }

  int ans = vb[0];
  for (int i = 1; i < n - 1; i++) {
    ans += min(vb[i], vb[i - 1]);
  }

  ans += vb.back();

  cout << ans << '\n';

  return 0;
}
