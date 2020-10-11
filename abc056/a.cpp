#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  char a, b;
  cin >> a >> b;
  if ((a == 'H' && b == 'H') || (a == 'D' && b == 'D')) {
    cout << 'H' << '\n';
  } else {
    cout << 'D' << '\n';
  }
  return 0;
}
