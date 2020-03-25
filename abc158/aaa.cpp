#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
  int N, P;
  string S;
  cin >> N >> P >> S;

  map<int, int> m;
  ll mod = 0;
  ll c = 1;
  ll ans = 0;
  for (ll i = N - 1; i >= 0; i--) {
    if (P == 2 || P == 5) {
      if ((S[i]-'0') % P == 0) {
        ans += i + 1;
      }
    }
    else {
      mod = (mod + c * (S[i]-'0')) % P;
      c = (c * 10) % P;
      ans += m[mod];
      m[mod]++;
      if (mod == 0) ans++;
    }
  }

  cout << ans << endl;

  return 0;
}

