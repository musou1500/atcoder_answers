#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b, ans;
  cin >> a >> b;
  for (int i = 1; i <= 3; i++) {
    if (a != i && b != i) {
      ans = i;
      break;
    }
  }

  cout << ans << '\n';
  return 0;
}
