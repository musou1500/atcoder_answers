#include <iostream>
#include <string>
#include <array>

using namespace std;

int main(int argc, const char *argv[])
{
  string s;
  cin >> s;

  char ch1, ch2;
  int cnt1, cnt2;
  ch1 = ch2 = '\0';
  cnt1 = cnt2 = 0;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ch1) {
      cnt1++;
    } else if (s[i] == ch2) {
      cnt2++;
    } else if (ch1 == '\0') {
      ch1 = s[i];
    } else if (ch2 == '\0') {
      ch2 = s[i];
    } else {
      cout << "No\n";
      return 0;
    }
  }

  if (cnt1 == cnt2) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  
  
  return 0;
}

