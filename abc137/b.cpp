#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[])
{
  int k, x;
  cin >> k >> x;

  for (int i = x - k + 1; i <= x + k - 1; i++) {
    if (i != x - k + 1) {
      cout << " ";
    }

    cout << i;
  }

  cout << "\n";
  
  return 0;
}

