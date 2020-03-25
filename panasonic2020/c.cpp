#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
  long long a, b, c;
  cin >> a >> b >> c;

  long long d = (c - a - b);
  if (d >= 0 && 4 * a * b < d * d) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  
  return 0;
}
