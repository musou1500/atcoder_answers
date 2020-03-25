#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
  int a, b;
  cin >> a >> b;
  
  b--;
  a--;
  int cnt = b / a;
  if (b % a > 0) {
    cnt++;
  }

  cout << cnt << "\n";
}
