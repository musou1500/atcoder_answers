#include <iostream>
#include <array>

using namespace std;

int main(int argc, const char *argv[])
{
  int n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < s.size(); i++) {
    s[i] += n;
    if (s[i] > 'Z') {
      s[i] = 'A' + s[i] - 'Z' - 1;
    }
  }
  
  cout << s << "\n";
  return 0;
}
