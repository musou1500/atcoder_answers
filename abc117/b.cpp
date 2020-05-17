#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<int> vl(n);
  for (int i = 0; i < n; ++i) {
    cin >> vl[i];
  }
  sort(vl.begin(), vl.end(), greater<int>());

  int sum = accumulate(vl.begin() + 1, vl.end(), 0);
  if (vl.front() < sum) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
  return 0;
}
