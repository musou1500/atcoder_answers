#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
  string n;
  cin >> n;
  for (int i = 0; i < n.size(); i++) {
    if (n[i] == '7') {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";

  return 0;
}
