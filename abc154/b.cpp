#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
  string s;
  cin >> s;

  string result;
  for (int i = 0; i < s.size(); i++) {
    result += "x";
  }

  cout << result << "\n";
  
  return 0;
}
