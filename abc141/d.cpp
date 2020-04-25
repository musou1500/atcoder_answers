#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  using ll = long long;
  int n, m;
  cin >> n >> m;

  priority_queue<ll, vector<ll>, less<ll>> q;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    q.push(a);
  }

  while (m > 0) {
    ll top = q.top();
    if (top <= 0) {
      break;
    }

    q.pop();
    q.push(top / 2);
    m--;
  }

  ll ans = 0;
  while (!q.empty()) {
    ans += q.top();
    q.pop();
  }
  cout << ans << '\n';

  return 0;
}
