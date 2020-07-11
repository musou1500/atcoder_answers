#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

// sが与えられる
int fn2(int s) {
  int ans = 0;
  while (s != 0) {
    auto bs = bitset<32>(s);
    int cnt = bs.count();
    s = s % cnt;
    ans++;
  }

  return ans;
}

using ll = long long;
int main(int argc, const char *argv[]) {
  int n;
  string x;
  cin >> n >> x;

  int cnt = count_if(x.begin(), x.end(), [](char c) { return c == '1'; });
  int md1 = cnt - 1, md2 = cnt + 1;

  vector<int> pow2_1(x.size() + 1, 1), pow2_2(x.size() + 1, 1);
  for (int i = 1; i < pow2_1.size(); ++i) {
    if (md1 > 0) {
      pow2_1[i] = pow2_1[i - 1] * 2 % md1;
    }

    pow2_2[i] = pow2_2[i - 1] * 2 % md2;
  }

  int x_md1 = 0, x_md2 = 0;
  for (int i = 0; i < x.size(); ++i) {
    char ch = *(x.rbegin() + i);
    if (ch == '1') {
      if (md1 > 0) {
        x_md1 = (x_md1 + pow2_1[i]) % md1;
      }

      x_md2 = (x_md2 + pow2_2[i]) % md2;
    }
  }

  // md1 : cnt-1
  // md2 : cnt+1
  vector<int> ans(x.size());
  for (int i = 0; i < x.size(); ++i) {
    int d = x[i] - '0';
    if (d) {
      // popcountは一つ減る
      if (md1 == 0) {
        ans[i] = 0;
      } else {
        int dd = x_md1 - pow2_1[x.size() - i - 1];
        if (dd < 0) {
          dd += md1;
        }

        ans[i] = fn2(dd % md1) + 1;
      }
    } else {
      // popcountは一つ増える
      ans[i] = fn2((x_md2 + pow2_2[x.size() - i - 1]) % md2) + 1;
    }
  }

  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << '\n';
  }

  return 0;
}
