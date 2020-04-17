#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  bool ans = false;
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      if (i * j == n) {
        ans = true;
        break;
      }
    }
  }

  cout << (ans ? "Yes" : "No") << '\n';

  return 0;
}
