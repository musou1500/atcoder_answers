#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  set<string> s;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    s.insert(str);
  }

  cout << s.size() << '\n';
  return 0;
}
