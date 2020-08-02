#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main(int argc, const char *argv[]) {
  ll k;
  cin >> k;

  ll cur = 7 % k, cnt = 1, ans;
  while (cur != 0 && cnt <= k + 10) {
    cur = (cur * 10 % k + 7) % k;
    cnt++;
  }

  if (cur == 0) {
    cout << cnt << '\n';
  } else {
    cout << "-1" << '\n';
  }

  return 0;
}
