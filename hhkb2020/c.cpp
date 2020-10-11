#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<int> vp(n);
  for (int i = 0; i < n; ++i) {
    cin >> vp[i];
  }

  set<int> nums;
  for (int i = 0; i < 300000; ++i) {
    nums.insert(i);
  }

  vector<int> v_ans;
  for (int i = 0; i < n; ++i) {
    nums.erase(vp[i]);
    v_ans.push_back(*nums.begin());
  }

  for (int i = 0; i < v_ans.size(); ++i) {
    cout << v_ans[i] << '\n';
  }
  return 0;
}
