#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
  char a, b;
  cin >> a >> b;

  string ab(b - '0', a);
  string ba(a - '0', b);

  cout << min(ab, ba) << "\n";
  return 0;
}
