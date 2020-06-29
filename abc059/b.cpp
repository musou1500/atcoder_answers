#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string a, b;
  cin >> a >> b;
  if (a.size() == b.size()) {
    if (a < b) {
      cout << "LESS" << '\n';
    } else if (a > b) {
      cout << "GREATER" << '\n';
    } else {
      cout << "EQUAL" << '\n';
    }
  } else {
    int s1 = a.size(), s2 = b.size();
    if (s1 < s2) {
      cout << "LESS" << '\n';
    } else if (s1 > s2) {
      cout << "GREATER" << '\n';
    } else {
      cout << "EQUAL" << '\n';
    }
  }
  return 0;
}
