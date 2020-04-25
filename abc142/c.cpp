#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<pair<int, int>> va(n);
  for (int i = 0; i < n; i++) {
    cin >> va[i].first;
    va[i].second = i;
  }

  sort(va.begin(), va.end());

  for (auto &p : va) {
    cout << p.second + 1 << '\n';
  }

  return 0;
}
