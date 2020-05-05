#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, k;
  cin >> n >> k;

  // 直接結ばれる頂点対(n - 1)個の距離は1になる
  // n(n - 1) / 2 - (n - 1) = (n - 1) * (n - 2) / 2
  if (k > (n - 1) * (n - 2) / 2) {
    cout << -1 << '\n';
    return 0;
  }

  stringstream ss;
  int m = 0;
  for (int i = 1; i < n; ++i) {
    m++;
    ss << 1 << ' ' << i + 1 << '\n';
  }

  int cnt = (n - 1) * (n - 2) / 2 - k;
  for (int i = 1; i < n - 1 && cnt > 0; ++i) {
    for (int j = i + 1; j < n && cnt > 0; ++j, --cnt) {
      ss << i + 1 << ' ' << j + 1 << '\n';
      m++;
    }
  }

  cout << m << '\n';
  cout << ss.str();
}
