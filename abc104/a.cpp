#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int r;
  cin >> r;
  if (r < 1200) {
    cout << "ABC" << '\n';
  } else if (r < 2800) {
    cout << "ARC" << '\n';
  } else {
    cout << "AGC" << '\n';
  }

  return 0;
}
