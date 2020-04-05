#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[])
{
  int n, m;
  cin >> n >> m;

  vector<pair<int, string>> submissions(m);
  vector<int> ac(n + 1, -1);
  for (int i = 0; i < m; i++) {
    cin >> submissions[i].first;
    cin >> submissions[i].second;
    if (submissions[i].second == "AC" && ac[submissions[i].first] < 0) {
      ac[submissions[i].first] = i;
    }
  }

  int penalty_cnts = 0;
  for (int i = 0; i < submissions.size(); i++) {
    auto &submission = submissions[i];
    if (ac[submission.first] > i && submission.second == "WA") {
      penalty_cnts++;
    }
  }

  int ac_cnt = count_if(ac.begin(), ac.end(), [](int n) { return n >= 0; });
  cout << ac_cnt << " " << penalty_cnts << "\n";
  return 0;
}
