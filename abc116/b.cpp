#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int s;
  cin >> s;

  auto f = [](int n) {
    if (n % 2 == 0) {
      return n / 2;
    } else {
      return 3 * n + 1;
    }
  };

  set<int> nums;
  nums.insert(s);
  int i = 1, prev_n = s, ans;
  while (true) {
    int n = f(prev_n);
    if (nums.count(n) > 0) {
      ans = i;
      break;
    }

    nums.insert(n);
    prev_n = n;
    i++;
  }

  cout << ans + 1 << '\n';
  return 0;
}
