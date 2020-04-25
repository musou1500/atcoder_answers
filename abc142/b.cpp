#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, k;
  cin >> n >> k;
  vector<int> vh(n);
  for (auto &h : vh) {
    cin >> h;
  }

  int ans = 0;
  for (auto &h : vh) {
    if (h >= k) {
      ans++;
    }
  }

  cout << ans << '\n';
  return 0;
}
