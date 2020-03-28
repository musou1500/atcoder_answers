#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[])
{
  int n;
  ll k;
  cin >> n >> k;

  vector<ll> positive_nums, negative_nums;
  ll z = 0;
  for (int i = 0; i < n; i++) {
    ll num;
    cin >> num;
    if (num > 0) {
      positive_nums.push_back(num);
    } else if (num < 0) {
      negative_nums.push_back(num);
    } else {
      z++;
    }
  }

  sort(positive_nums.begin(), positive_nums.end());
  sort(negative_nums.begin(), negative_nums.end());
  
  ll p_size = positive_nums.size(),
     n_size = negative_nums.size(),
     negative_cnt = p_size * n_size,
     zero_cnt = z * (p_size + n_size) + z * (z - 1) / 2,
     ans;

  if (negative_cnt >= k) {
    ll left = -1e18 - 1ll, right = -1;
    while (right - left > 1) {
      ll mid = (left + right) / 2;
      ll cnt = accumulate(positive_nums.begin(), positive_nums.end(), 0ll,
          [&](auto acc, auto num) {
            auto right_it = upper_bound(
                negative_nums.begin(),
                negative_nums.end(),
                (mid - num + 1) / num);
            return acc + distance(negative_nums.begin(), right_it);
          });

      if (cnt < k) {
        left = mid;
      } else {
        right = mid;
      }
    }

    ans = right;
  } else if (negative_cnt + zero_cnt >= k) {
    ans = 0;
  } else {
    ll left = 1, right = 1e18 + 1ll;
    while(right - left > 1) {
      ll mid = (left + right) / 2;
      ll cnt = negative_cnt + zero_cnt;
      if (positive_nums.size() > 1) {
        for (auto it = positive_nums.begin(); it != positive_nums.end() - 1; it++) {
          auto right_it = upper_bound(
              it + 1,
              positive_nums.end(),
              mid / *it);
          cnt += distance(it + 1, right_it);
        }
      }

      if (negative_nums.size() > 1) {
        for (auto it = negative_nums.begin(); it != negative_nums.end() - 1; it++) {
          auto left_it = lower_bound(
              it + 1,
              negative_nums.end(),
              mid / *it);
          cnt += distance(left_it, negative_nums.end());
        }
      }

      if (cnt < k) {
        left = mid;
      } else {
        right = mid;
      }
    }

    ans = right;
  }

  cout << ans << "\n";
  return 0;
}
