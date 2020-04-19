#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<int> va(n);
  for (int i = 0; i < n; i++) {
    cin >> va[i];
    va[i]--;
  }

  vector<int> vb(n);
  for (int i = 0; i < n; i++) {
    cin >> vb[i];
  }

  vector<int> vc(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> vc[i];
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += vb[va[i]];
    if (i >= 1 && va[i - 1] == va[i] - 1) {
      ans += vc[va[i - 1]];
    }
  }

  cout << ans << '\n';

  return 0;
}
