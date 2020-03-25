#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  int n;
  unsigned long long k;
  cin >> n >> k;

  vector<unsigned long long> a(n);
  vector<unsigned long long> com_sums(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    com_sums[i + 1] = com_sums[i] + a[i];
  }

  unsigned long long cnt = 0;
  for (int i = 0; i < n; i++) {
    int left = i, right = com_sums.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      unsigned long long sum = com_sums[mid] - com_sums[i];
      if (sum < k) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    if (left < com_sums.size()) {
      cnt += n - left + 1;
    }
  }

  cout << cnt << "\n";
  
  return 0;
}

