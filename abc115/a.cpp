#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int d;
  cin >> d;
  cout << "Christmas";
  if (d == 24) {
    cout << " Eve";
  } else if (d == 23) {
    cout << " Eve Eve";
  } else if (d == 22) {
    cout << " Eve Eve Eve";
  }

  cout << '\n';
  return 0;
}
