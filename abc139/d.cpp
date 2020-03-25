#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  unsigned long long n;
  cin >> n;
  n--;
  cout << (n + 1) * n / 2 << "\n";
}
