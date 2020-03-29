#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main(int argc, const char *argv[])
{
  // 赤，緑，無色のリンゴ
  int x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<ll> p(a);
  vector<ll> q(b);
  vector<ll> r(c);
  for (int i = 0; i < a; i++) cin >> p[i];
  for (int i = 0; i < b; i++) cin >> q[i];
  for (int i = 0; i < c; i++) cin >> r[i];

  sort(p.begin(), p.end(), greater<ll>());
  sort(q.begin(), q.end(), greater<ll>());
  sort(r.begin(), r.end(), greater<ll>());

  vector<ll> apples;
  for (int i = 0; i < x; i++) apples.push_back(p[i]);
  for (int i = 0; i < y; i++) apples.push_back(q[i]);

  // 小さい順に並んでる
  sort(apples.begin(), apples.end());

  for (int i = 0, j = 0; i < r.size() && j < apples.size();) {
    if (apples[j] < r[i]) {
      apples[j] = r[i];
      i++;
      j++;
    } else {
      break;
    }
  }

  cout << accumulate(apples.begin(), apples.end(), 0ll) << "\n";
  return 0;
}
