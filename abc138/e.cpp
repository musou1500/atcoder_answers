#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <array>

using namespace std;

int main(int argc, const char *argv[])
{
  string s, t;
  cin >> s >> t;
  
  array<set<int>, 26> s_positions;
  for (int i = 0; i < s.size(); i++) {
    s_positions[s[i] - 'a'].insert(i);
  }
  
  bool exists = all_of(t.begin(), t.end(),
      [&](char ch) { return s_positions[ch - 'a'].size() > 0; });
  if (!exists) {
    cout << "-1\n";
    return 0;
  }

  int s_cur = 0, t_cur = 0;
  long long repeat_cnt = 0;
  while (t_cur < t.size()) {
    char t_ch = t[t_cur];
    auto &ch_positions = s_positions[t_ch - 'a'];
    auto it = ch_positions.lower_bound(s_cur);
    if (it != ch_positions.end()) {
      s_cur = *it + 1;
      t_cur++;
    } else {
      s_cur = 0;
      repeat_cnt++;
    }
  }

  cout << repeat_cnt * static_cast<long long>(s.size()) + s_cur << "\n";
  return 0;
}
