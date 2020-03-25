#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
  string s;
  cin >> s;
  
  string result = "Good";
  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == s[i + 1]) {
      result = "Bad";
      break;
    }
  }

  cout << result << "\n";
  return 0;
}
