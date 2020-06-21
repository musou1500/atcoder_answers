#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, t;
  cin >> n >> t;

  vector<int> vc;
  for (int i = 0; i < n; ++i) {
    int c, t2;
    cin >> c >> t2;
    if (t2 > t) {
      continue;
    }

    vc.push_back(c);
  }

  if (vc.size() == 0) {
    cout << "TLE" << '\n';
    return 0;
  }

  cout << *min_element(vc.begin(), vc.end()) << '\n';
  return 0;
}
