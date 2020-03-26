#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
  string s, t, u;
  int a, b;
  cin >> s >> t >> a >> b >> u;

  if (u == s) {
    cout << a - 1 << " " << b << "\n";
  } else {
    cout << a << " " << b - 1 << "\n";
  }
  return 0;
}
