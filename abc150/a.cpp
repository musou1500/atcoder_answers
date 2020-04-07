#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
  int k, x;
  cin >> k >> x;
  if (k * 500 >= x) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
