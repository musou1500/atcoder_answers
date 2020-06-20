#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, k;
  cin >> n >> k;
  vector<int> vd(k);
  for (int i = 0; i < k; ++i) {
    cin >> vd[i];
  }

  sort(vd.begin(), vd.end());

  auto check = [&](int m) {
    string s = to_string(m);
    bool ok = true;
    for (int i = 0; i < s.size(); i++) {
      int d = s[i] - '0';
      bool ex = binary_search(vd.begin(), vd.end(), d);
      if (ex) {
        ok = false;
        break;
      }
    }

    return ok;
  };

  int i = n, ans;
  while (true) {
    if (check(i)) {
      ans = i;
      break;
    }

    i++;
  }

  cout << i << '\n';
  return 0;
}
