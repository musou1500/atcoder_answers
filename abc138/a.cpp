#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
  int a;
  string s;
  cin >> a >> s;
  if (a >= 3200) {
    cout << s << "\n";
  } else {
    cout << "red\n";
  }

  return 0;
}
