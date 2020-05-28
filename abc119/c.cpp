#include <bits/stdc++.h>

using namespace std;

pair<int, int> solve(vector<int> &vl, int a, int state) {
  // 消費したmp, 使用後の状態
  pair<int, int> ans{-1, -1};
  for (int i = 1; i < (1 << vl.size()); ++i) {
    if (state & i) {
      continue;
    }

    int sum = 0, cnt = 0;
    for (int j = 0; j < vl.size(); ++j) {
      if (i & (1 << j)) {
        sum += vl[j];
        cnt++;
      }
    }

    int mp = abs(sum - a) + (cnt - 1) * 10;
    if (ans.first < 0 || mp < ans.first) {
      ans.first = mp;
      ans.second = state | i;
    }
  }

  return ans;
}

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<int> abc(3);
  for (int i = 0; i < abc.size(); ++i) {
    cin >> abc[i];
  }

  sort(abc.begin(), abc.end());

  vector<int> vl(n);
  for (int i = 0; i < n; ++i) {
    cin >> vl[i];
  }

  int ans = -1;
  do {
    int mp = 0, state = 0;
    bool ok = true;
    for (auto a : abc) {
      auto res = solve(vl, a, state);
      if (res.first < 0) {
        ok = false;
        break;
      }

      mp += res.first;
      state = res.second;
    }

    if (ok && (ans < 0 || mp < ans)) {
      ans = mp;
    }

  } while (next_permutation(abc.begin(), abc.end()));

  cout << ans << '\n';

  return 0;
}
