#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(int argc, const char *argv[]) {
  //
  int a, b;
  cin >> a >> b;
  cout << max(0, a - b * 2) << '\n';
  return 0;
}
