#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  vector<int> ans;
  for (int i = 0; i < s.size() - 2; ++i) {
    int n = 0, pow10 = 1;
    for (int j = i + 2; i <= j; --j, pow10 *= 10) {
      n += pow10 * (s[j] - '0');
    }

    ans.push_back(abs(753 - n));
  }

  cout << *min_element(ans.begin(), ans.end()) << '\n';
  return 0;
}
