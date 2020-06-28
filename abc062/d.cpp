#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<ll> va(3 * n);
  for (int i = 0; i < va.size(); ++i) {
    cin >> va[i];
  }

  priority_queue<ll> rq;
  vector<ll> r(n + 1);
  for (auto it = va.rbegin(); it != va.rbegin() + n; it++) {
    r[0] += *it;
    rq.push(*it);
  }

  ll s = r[0];
  for (int i = 1; i < r.size(); ++i) {
    rq.push(*(va.rbegin() + n + i - 1));
    s += *(va.rbegin() + n + i - 1);
    ll m = rq.top();
    rq.pop();
    s -= m;
    r[i] = s;
  }

  priority_queue<ll, vector<ll>, greater<ll>> q;
  vector<ll> f(n + 1);
  for (auto it = va.begin(); it != va.begin() + n; it++) {
    f[0] += *it;
    q.push(*it);
  }

  s = f[0];
  for (int i = 1; i < f.size(); ++i) {
    q.push(*(va.begin() + n + i - 1));
    s += *(va.begin() + n + i - 1);
    ll m = q.top();
    q.pop();
    s -= m;
    f[i] = s;
  }

  ll ans = f.front() - r.back();
  for (int i = 0; i < f.size(); ++i) {
    ll score = f[i] - r[r.size() - i - 1];
    ans = max(ans, score);
  }

  cout << ans << '\n';

  return 0;
}
