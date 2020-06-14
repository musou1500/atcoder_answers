#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  int n, q;
  cin >> n >> q;

  // vp[i]: 幼児iの所属, レート
  // v_rate[i]: 幼稚園iに所属する幼児のレート一覧
  // m_rate: 最強幼児のレートの順序付き多重集合
  vector<pair<int, ll>> vp(n);
  vector<multiset<ll, greater<ll>>> v_rate(2 * 100000);
  multiset<ll> m_rate;

  for (int i = 0; i < n; ++i) {
    ll a;
    int b;
    cin >> a >> b;
    b--;

    // a, b = レート，所属
    vp[i].first = b;
    vp[i].second = a;
    v_rate[b].insert(a);
  }

  for (auto &m : v_rate) {
    if (!m.empty()) {
      m_rate.insert(*m.begin());
    }
  }

  vector<int> ans(q);
  for (int i = 0; i < q; ++i) {
    int c, d;
    cin >> c >> d;
    c--, d--;

    // 幼児Cの所属
    auto &p = vp[c];

    // 転園元を更新
    m_rate.erase(m_rate.find(*v_rate[p.first].begin()));
    v_rate[p.first].erase(v_rate[p.first].find(p.second));
    if (!v_rate[p.first].empty()) {
      m_rate.insert(*v_rate[p.first].begin());
    }

    // 転園先を更新
    if (!v_rate[d].empty()) {
      m_rate.erase(m_rate.find(*v_rate[d].begin()));
    }
    v_rate[d].insert(p.second);
    m_rate.insert(*v_rate[d].begin());

    p.first = d;

    ans[i] = *m_rate.begin();
  }

  for (auto a : ans) {
    cout << a << '\n';
  }

  return 0;
}
