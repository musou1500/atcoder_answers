#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[]) {
  //
  int n, k;
  string s;
  cin >> n >> k >> s;

  int cnt = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == s[i + 1]) {
      cnt++;
    }
  }

  cnt += 2 * k;
  cout << min(n - 1, cnt) << '\n';
  return 0;
}
