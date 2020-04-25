#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;

  bool ans = true;
  for (int i = 0; i < s.size(); i++) {
    string s1 = "RUD", s2 = "LUD";
    if ((i % 2 == 1 && s2.find(s[i]) == string::npos) ||
        (i % 2 == 0 && s1.find(s[i]) == string::npos)) {
      ans = false;
      break;
    }
  }

  cout << (ans ? "Yes" : "No") << '\n';

  return 0;
}
