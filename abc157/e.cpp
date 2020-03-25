#include <algorithm>
#include <iostream>
#include <string>
#include <set>
#include <array>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  int n, q;
  string s;
  array<set<int>, 26> char_positions;
  cin >> n >> s >> q;
  for (int i = 0; i < s.size(); i++) {
    char_positions[s[i] - 'a'].insert(i);
  }

  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int p1;
      char p2;
      cin >> p1 >> p2;
      p1--;
      char_positions[s[p1] - 'a'].erase(p1);
      s[p1] = p2;
      char_positions[s[p1] - 'a'].insert(p1);
    } else {
      int p1, p2;
      cin >> p1 >> p2;
      p1--;
      p2--;
      int cnt = count_if(char_positions.begin(), char_positions.end(),
          [&](auto &positions) {
            auto pos_it = positions.lower_bound(p1);
            return pos_it != positions.end() && *pos_it <= p2;
          });
      cout << cnt << "\n";
    }
  }

  return 0;
}
