#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<string> vs(n);
  for (int i = 0; i < n; ++i) {
    cin >> vs[i];
  }

  int ac, wa, tle, re;
  ac = wa = tle = re = 0;
  for (auto &s : vs) {
    if (s == "AC") {
      ac++;
    } else if (s == "WA") {
      wa++;
    } else if (s == "TLE") {
      tle++;
    } else {
      re++;
    }
  }

  cout << "AC x " << ac << '\n';
  cout << "WA x " << wa << '\n';
  cout << "TLE x " << tle << '\n';
  cout << "RE x " << re << '\n';
  return 0;
}
