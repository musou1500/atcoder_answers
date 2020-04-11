#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  int cur = 1, ans = 0, found = false;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a == cur) {
      found = true;
      cur++;
    } else {
      ans++;
    }
  }

  cout << (found ? ans : -1) << '\n';

  return 0;
}
