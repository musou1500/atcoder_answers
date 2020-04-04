#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  int n, k, c;
  string s;
  cin >> n >> k >> c >> s;

  vector<int> d1;
  for (int i = 0; i < n && d1.size() < k; i++) {
    if (s[i] == 'o' && (d1.empty() || i - d1.back() > c)) {
      d1.push_back(i);
    }
  }

  vector<int> d2;
  for (int i = n - 1; i >= 0 && d2.size() < k; i--) {
    if (s[i] == 'o' && (d2.empty() || d2.back() - i > c)) {
      d2.push_back(i);
    }
  }

  vector<int> ans;
  for (int i = 0; i < k; i++) {
    if (d1[i] == d2[k - i - 1]) {
      ans.push_back(d1[i]);
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] + 1;
    cout << (i == ans.size() - 1 ? '\n' : ' ');
  }
  
  return 0;
}
