#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;

  using pint = pair<int, int>;
  auto compare = [](pint &a, pint &b) { return b.second < a.second; };
  priority_queue<pint, vector<pint>, decltype(compare)> jobs(compare);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    jobs.push(make_pair(a, b));
  }
  
  int t = 0;
  string ans = "Yes";
  while (!jobs.empty()) {
    auto &job = jobs.top();
    t += job.first;
    if (t > job.second) {
      ans = "No";
      break;
    }

    jobs.pop();
  }

  cout << ans << "\n";
  return 0;
}
