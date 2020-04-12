#include <algorithm>
#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// citiesのうち，n個の街に訪れるときの平均距離

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<pair<int, int>> cities(n);

  for (int i = 0; i < n; i++) {
    cin >> cities[i].first >> cities[i].second;
  }

  vector<int> order(n);
  iota(order.begin(), order.end(), 0);

  double ans = 0;
  int cnt = 0;
  do {
    // 平均値
    double dist = 0;
    for (int i = 0; i < n - 1; i++) {
      auto c1 = cities[order[i]], c2 = cities[order[i + 1]];
      dist += hypot(c1.first - c2.first, c1.second - c2.second);
    }

    ans += dist;
    cnt++;
  } while (next_permutation(order.begin(), order.end()));

  cout << fixed << setprecision(9) << ans / cnt << '\n';
  return 0;
}
