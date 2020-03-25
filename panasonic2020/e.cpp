#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  string a, b, c;
  cin >> a >> b >> c;

  vector<string> strs{b, c};
  string result = a;
  for (auto s : strs) {

    // 前からマッチしている部分を探す
    int max_match_len = 0, match_len = 0, match_start = -1;
    for (int i = 0; i < result.size(); i++) {
      if (result[i] == '?' || s[i] == result[i]) {
        match_len++;
        continue;
      }

      if (max_match_len < match_len) {
        max_match_len = match_len;
        match_start = i - match_len;
      }
      match_len = 0;
    }

    // 後ろからマッチしている部分を探す
    int rev_max_match_len = 0, rev_match_len = 0, rev_match_start = -1;
    for (int i = s.size(); i >= 0; i--) {
      if (result[i] == '?' || s[i] == result[i]) {
        match_len++;
        continue;
      }

      if (rev_max_match_len < rev_match_len) {
        rev_max_match_len = rev_match_len;
        rev_match_start = i - rev_match_len;
      }
      rev_match_len = 0;
    }
    
    cout << match_len << " " << rev_match_len << "\n";
  }

  cout << result.size() << "\n";
}
