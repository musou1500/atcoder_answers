#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> vm(n);
  int min_m = 2000;
  for (int i = 0; i < n; i++) {
    cin >> vm[i];
    x -= vm[i];
    min_m = min(min_m, vm[i]);
  }

  cout << n + (x / min_m) << '\n';
}

