#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve_pat1(ll h, ll w) {
  if (h % 3 == 0) {
    return 0;
  } else {
    return w;
  }
}

ll solve_pat2(ll h, ll w) {
  ll b_h = h / 2;
  ll ans = h * w;
  for (ll i = 1; i <= w - 1; ++i) {
    ll b_w = w - i;
    ll area1 = i * h;
    ll area2 = b_h * b_w;
    ll area3 = h * w - (area1 + area2);
    ans = min(ans, max({area1, area2, area3}) - min({area1, area2, area3}));
  }

  return ans;
}

int main(int argc, const char *argv[]) {
  ll h, w;
  cin >> h >> w;
  vector<ll> ans{
      solve_pat2(h, w),
      solve_pat2(w, h),
  };

  if (h >= 3) {
    ans.push_back(solve_pat1(h, w));
  }

  if (w >= 3) {
    ans.push_back(solve_pat1(w, h));
  }

  cout << *min_element(ans.begin(), ans.end()) << '\n';
  return 0;
}
