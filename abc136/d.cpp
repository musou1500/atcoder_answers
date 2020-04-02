#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  string s;
  cin >> s;
  vector<int> ans(s.size(), 0);
  int odd_cnt = 1, even_cnt = 1;

  for (int i = 0; i < s.size() - 1; i++) {
    if (s[i] == 'L') {
      continue;
    }

    bool is_even_idx = i % 2 == 0;
    if (s[i + 1] == 'R') {
      if (is_even_idx) {
        even_cnt++;
      } else {
        odd_cnt++;
      }
    } else {
      ans[i] += is_even_idx ? even_cnt : odd_cnt;
      ans[i + 1] += is_even_idx ? odd_cnt : even_cnt;
      even_cnt = odd_cnt = 1;
    }
  }

  even_cnt = odd_cnt = 0;
  for (int i = s.size() - 1; i >= 1; i--) {
    if (s[i] == 'R') {
      continue;
    }

    bool is_even_idx = i % 2 == 0;
    if (s[i - 1] == 'L') {
      if (is_even_idx) {
        even_cnt++;
      } else {
        odd_cnt++;
      }
    } else {
      ans[i] += is_even_idx ? even_cnt : odd_cnt;
      ans[i - 1] += is_even_idx ? odd_cnt : even_cnt;
      even_cnt = odd_cnt = 0;
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    cout << (i == ans.size() - 1 ? '\n' : ' ');
  }
  
  return 0;
}
