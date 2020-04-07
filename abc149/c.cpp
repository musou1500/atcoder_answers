#include <iostream>

using namespace std;

bool is_prime(int n) {
  for (int i = 2; i * i < n; i++) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

int main(int argc, const char *argv[]) {
  int x;
  cin >> x;
  while (!is_prime(x)) {
    x++;
  }

  cout << x << "\n";
  return 0;
}
