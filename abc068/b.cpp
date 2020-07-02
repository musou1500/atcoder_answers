#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  int max_cnt = 0, ans = 1;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    int i_org = i;
    while (i % 2 == 0) {
      cnt++;
      i /= 2;
    }

    i = i_org;
    if (cnt > max_cnt) {
      max_cnt = cnt;
      ans = i;
    }
  }

  cout << ans << '\n';
  return 0;
}

