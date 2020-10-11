#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  char x, y;
  cin >> x >> y;
  if (x == y) {
    cout << '=' << '\n';
  } else if (x < y) {
    cout << '<' << '\n';
  } else {
    cout << '>' << '\n';
  }

  return 0;
}
