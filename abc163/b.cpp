#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<int> va(m);
  for (int i = 0; i < m; i++) {
    cin >> va[i];
  }

  int sum = 0;
  for (auto a : va) {
    sum += a;
  }

  if (sum > n) {
    cout << -1 << '\n';
  } else {
    cout << n - sum << '\n';
  }

  return 0;
}
