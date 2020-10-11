#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, z, w;
  cin >> n >> z >> w;
  vector<int> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  if (va.size() == 1) {
    cout << abs(va.front() - w) << '\n';
  } else {
    cout << max(abs(va.back() - w), abs(va[va.size() - 2] - va.back())) << '\n';
  }
}

