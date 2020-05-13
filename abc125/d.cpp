#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  using ll = long long;
  int n;
  cin >> n;

  vector<ll> va(n);
  int neg_cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> va[i];
    neg_cnt += va[i] < 0;
  }

  sort(va.begin(), va.end());
  int i = 0;
  for (i = 0; i < (neg_cnt - neg_cnt % 2); i++) {
    va[i] *= -1;
  }

  if (neg_cnt % 2 == 1 && neg_cnt < va.size() &&
      abs(va[neg_cnt - 1]) > va[neg_cnt]) {
    va[neg_cnt - 1] *= -1;
    va[neg_cnt] *= -1;
  }

  ll sum = accumulate(va.begin(), va.end(), 0ll, plus<ll>());
  cout << sum << '\n';
  return 0;
}

