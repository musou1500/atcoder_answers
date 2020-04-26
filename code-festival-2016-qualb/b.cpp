#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, a, b;
  string s;
  cin >> n >> a >> b >> s;

  int cnt = 0, ext_rank = 1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'c') {
      cout << "No\n";
      continue;
    }

    if (s[i] == 'a') {
      if (a + b > cnt) {
        cout << "Yes" << '\n';
        cnt++;
      } else {
        cout << "No\n";
      }
    } else {
      if (a + b > cnt && ext_rank <= b) {
        cout << "Yes\n";
        cnt++;
        ext_rank++;
      } else {
        cout << "No\n";
      }
    }
  }

  return 0;
}
