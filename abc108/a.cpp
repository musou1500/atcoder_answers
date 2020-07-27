#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int k;
  cin >> k;
  int odd = (k + 1) / 2;
  int even = k / 2;
  cout << odd * even << '\n';
  return 0;
}
