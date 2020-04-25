#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  using ll = long long;
  ll n, k, q;
  cin >> n >> k >> q;

  vector<ll> pts(n, k - q);
  for (int i = 0; i < q; i++) {
    int a;
    cin >> a;
    a--;
    pts[a]++;
  }

  for (int i = 0; i < n; i++) {
    cout << (pts[i] > 0 ? "Yes" : "No") << '\n';
  }

  return 0;
}
