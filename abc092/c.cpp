#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<int> va{0};
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    va.push_back(a);
  }
  va.push_back(0);

  int dist_sum = 0;
  for (int i = 0; i < va.size() - 1; ++i) {
    dist_sum += abs(va[i] - va[i + 1]);
  }

  for (int i = 1; i < va.size() - 1; ++i) {
    int d = abs(va[i] - va[i - 1]) + abs(va[i] - va[i + 1]);
    cout << dist_sum - (d - abs(va[i - 1] - va[i + 1])) << '\n';
  }
  return 0;
}
