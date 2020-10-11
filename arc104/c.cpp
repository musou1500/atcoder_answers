#include <bits/stdc++.h>

using namespace std;

bool chk(vector<pair<int, int>> &vp) {
  int n2 = vp.size() * 2;
  vector<int> used(n2 + 1, false);
  for (auto [a, b] : vp) {
    if (a == -1 && b == -1) {
      continue;
    }

    if (a >= n2 || (b != -1 && b < 2)) {
      return false;
    }

    if (a == -1 || b == -1) {
      continue;
    }

    if (used[a] || used[b] || a >= b) {
      return false;
    }

    used[a] = true;
    used[b] = true;
  }

  for (int i = 0; i < vp.size() - 1; ++i) {
    for (int j = i + 1; j < vp.size(); ++j) {
      auto p1 = vp[i], p2 = vp[j];
      if (p1.first == -1 || p1.second == -1 || p2.first == -1 ||
          p2.second == -1) {
        continue;
      }

      if (p2.second < p1.first || p1.second < p2.first) {
        continue;
      } else if (p1.second - p1.first != p2.second - p2.first) {
        return false;
      }
    }
  }

  return true;
};

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<pair<int, int>> vp(n);
  vector<int> vr(2 * n + 1, 1);
  for (auto &p : vp) {
    cin >> p.first >> p.second;
    for (int i = p.first; i <= p.second; ++i) {
      vr[i] = p.second - p.first;
    }
  }

  if (!chk(vp)) {
    cout << "No" << '\n';
    return 0;
  }

  for (auto &p : vp) {
    if (p.first == -1 && p.second == -1) {
      continue;
    }

    if (p.first == -1) {
      p.first = p.second - vr[p.second];
    } else if (p.second == -1) {
      p.second = p.first + vr[p.first];
    }
  }

  if (!chk(vp)) {
    cout << "No" << '\n';
  } else {
    cout << "Yes" << '\n';
  }

  return 0;
}
