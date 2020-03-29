#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
  string s;
  cin >> s;

  if (s[2] == s[3] && s[4] == s[5]) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  
  return 0;
}
