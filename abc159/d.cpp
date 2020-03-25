#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
using ull = unsigned long long;

int main(int argc, const char *argv[])
{
  int size;
  cin >> size;
  vector<int> a(size);
  vector<int> cnts(size + 1, 0);
  for (auto &n : a) {
    cin >> n;
    cnts[n]++;
  }

  ull sum = accumulate(cnts.begin(), cnts.end(), 0ull,
      [] (ull acc, ull n) { return acc + n * (n - 1) / 2; });
  for (auto n : a) {
    cout << sum - cnts[n] + 1 << "\n";
  }

  return 0;
}

