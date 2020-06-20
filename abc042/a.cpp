#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  vector<int> vn(3);
  for (int i = 0; i < 3; ++i) {
    cin >> vn[i];
  }

  sort(vn.begin(), vn.end());

  if (vn[0] == 5 && vn[1] == 5 && vn[2] == 7) {
    cout << "YES" << '\n';
  } else {
    cout << "NO" << '\n';
  }
  return 0;
}
