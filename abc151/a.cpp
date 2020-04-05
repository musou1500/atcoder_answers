#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
  char ch;
  cin >> ch;
  cout << static_cast<char>(ch + 1) << '\n';
  return 0;
}
