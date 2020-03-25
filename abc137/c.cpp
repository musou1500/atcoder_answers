#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

using ll = long long;

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;

  unordered_map<string, ll> cnts;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    cnts[s]++;
  }

  long long ans = 0;
  for (auto &cnt : cnts) {
    if (cnt.second >= 2) {
      ans += cnt.second * (cnt.second - 1) / 2;
    }
  }
 
  cout << ans << "\n";
  return 0;
}
