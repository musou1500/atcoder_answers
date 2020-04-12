#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, t;
  cin >> n >> t;

  vector<pair<int, int>> foods(n);
  for (auto &f : foods) {
    cin >> f.first >> f.second;
  }

  sort(foods.begin(), foods.end());

  return 0;
}
