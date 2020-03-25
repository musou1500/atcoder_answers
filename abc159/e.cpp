#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

int main(int argc, const char *argv[])
{
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  for (int i = 0; i < h; i++) cin >> s[i];
  int ans = h + w + 1;
  for (int bit = 0; bit < (1 << (h - 1)); bit++) {
    bitset<16> bs(bit);
    int x = 0, split_cnt = bs.count();
    bool ok = true;
    while (x < w && ok) {
      bool exceeded = false;
      vector<int> white_cnts(bs.count() + 1, 0);
      int left = x;
      for (; !exceeded && x < w; x++) {
        for (int y = 0, cur = 0; y < h; y++) {
          white_cnts[cur] += s[y][x] - '0';
          exceeded = exceeded || white_cnts[cur] > k;
          cur += bs[y];
        }
      }

      if (exceeded) {
        split_cnt++;
        x--;
      }

      ok = !exceeded || left != x;
    }

    ans = ok ? min(ans, split_cnt) : ans;
  }

  cout << ans << "\n";

  return 0;
}

