#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;

  using ll = long long;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<ll> ans(a.size(), 0);
  // 最初の山に降った雨量を決定する
  ans[0] = accumulate(a.begin(), a.end(), 0ll);
  for (int i = 1; i < a.size() - 1; i += 2) {
    ans[0] -= a[i] * 2; 
  }

  // 残りの山に降った雨量を決定する
  for (int i = 1; i < a.size(); i++) {
    ans[i] = 2 * a[i - 1] - ans[i - 1];
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    cout << (i == ans.size() - 1 ? '\n' : ' ');
  }

  return 0;
}
