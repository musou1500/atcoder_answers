#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int main(int argc, const char *argv[])
{
  int x, y, z;
  cin >> x >> y >> z;
  swap(x, y);
  swap(x, z);

  cout << x << " ";
  cout << y << " ";
  cout << z << "\n";
  return 0;
}
