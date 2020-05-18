#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int k;
  string s;
  cin >> k >> s;
  if (s.size() <= k) {
    cout << s << '\n';
  } else {
    for (int i = 0; i < k; ++i) {
      cout << s[i];
    }

    cout << "..." << '\n';
  }
  return 0;
}
