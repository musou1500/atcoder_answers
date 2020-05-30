#include <iostream>

using namespace std;

int main() {
  int cnt = 0;
  for (int i = 0; i < 3; i++) {
    char c;
    cin >> c;
    if (c == 'o') {
      cnt++;
    }
  }

  cout << 700 + 100 * cnt << '\n';
}

