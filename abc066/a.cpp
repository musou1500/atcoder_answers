#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[]) {
  vector<int> va(3);
  for (int i = 0; i < va.size(); ++i) {
    cin >> va[i];
  }

  sort(va.begin(), va.end());

  cout << va[0] + va[1] << '\n';
  return 0;
}
