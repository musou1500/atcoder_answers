#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  int month = stoi(s.substr(5, 2));
  int dom = stoi(s.substr(8, 2));
  if (month > 4) {
    cout << "TBD" << '\n';
  } else if (month < 4) {
    cout << "Heisei" << '\n';
  } else {
    if (dom > 30) {
      cout << "TBD" << '\n';
    } else {
      cout << "Heisei" << '\n';
    }
  }
  return 0;
}
