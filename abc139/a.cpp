#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
  string s, t;
  cin >> s >> t;

  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == t[i]) {
      cnt++;
    }
  }

  cout << cnt << "\n";
  return 0;
}
