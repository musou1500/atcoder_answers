#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

using Memo = vector<unordered_map<int, bool>>;

void solve(vector<int> &p, set<int> &ans,  Memo &memo, int offset = 0, int acc = 0) {
  if (memo[offset][acc]) {
    return;
  }

  if (offset == p.size()) {
    ans.insert(acc);
  } else {
    solve(p, ans, memo, offset + 1, acc);
    solve(p, ans, memo, offset + 1, acc + p[offset]);
  }

  memo[offset][acc] = true;
}

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  Memo memo(p.size() + 1); 

  set<int> ans;
  solve(p, ans, memo);
  cout << ans.size() << "\n";
  return 0;
}
