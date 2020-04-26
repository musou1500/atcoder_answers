#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int s, w;
  cin >> s >> w;
  if (w >= s) {
    cout << "unsafe\n";
  } else {
    cout << "safe\n";
  }
  return 0;
}
