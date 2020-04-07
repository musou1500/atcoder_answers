#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  string s;
  cin >> n >> s;

  int ans = 0;
  for (int i = 0; i <= s.size() - 3; i++) {
    if (s.substr(i, 3) == "ABC") {
      ans++;
    }
  }

  cout << ans << "\n";
  return 0;
}
