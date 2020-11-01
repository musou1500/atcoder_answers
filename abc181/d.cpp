#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  array<int, 10> cnts{0};
  for (int i = 0; i < s.size(); ++i) {
    cnts[s[i] - '0']++;
  }

  if (s.size() == 1) {
    int n = s.front() - '0';
    if (n % 8 == 0) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }
    return 0;
  } else if (s.size() == 2) {
    int n1 = (s[0] - '0');
    int n2 = (s[1] - '0');
    int n3 = n1 * 10 + n2;
    int n4 = n2 * 10 + n1;
    if (n3 % 8 == 0 || n4 % 8 == 0) {
      cout << "Yes" << '\n';
    } else {
      cout << "No" << '\n';
    }

    return 0;
  }

  // < 1000
  for (int i = 104; i < 1000; i += 8) {
    // s1 -> s2?
    string s2 = to_string(i);
    array<int, 10> cnts2{0};
    for (auto c : s2) {
      cnts2[c - '0']++;
    }

    bool ok = true;
    for (int j = 0; j <= 9; ++j) {
      if (cnts2[j] > cnts[j]) {
        ok = false;
        break;
      }
    }

    if (ok) {
      cout << "Yes" << '\n';
      return 0;
    }
  }

  cout << "No" << '\n';
  return 0;
}
