#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  string s;
  cin >> n >> s;
  if (s.size() % 2 == 1) {
    cout << "No\n";
    return 0;
  }

  bool ans = true;
  for (int i = 0; i < s.size() / 2; i++) {
    if (s[i] != s[i + s.size() / 2]) {
      ans = false;
      break;
    }
  }

  cout << (ans ? "Yes\n" : "No\n");
  return 0;
}
