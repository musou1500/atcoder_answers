#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;

int mod_mult(const vector<long long> &terms) {
  int ans = 1;
  for (auto &term : terms) {
    ans = (term % mod * ans) % mod;
  }

  return ans;
}

int main(int argc, const char *argv[])
{
  int n, ans = 0;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int j = 0; j < 61; j++) {
    int cnt0 = 0, cnt1 = 0;
    long long mask = 1LL << j;
    for (auto num : a) {
      if (num & mask) {
        cnt1++;
      } else {
        cnt0++;
      }  
    }

    ans += mod_mult({cnt0, cnt1, mask});
    ans = ans % mod;
  }

  cout << ans << "\n";
  return 0;
}
