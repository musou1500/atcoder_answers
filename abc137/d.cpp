#include <functional>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, const char *argv[])
{
  int n, m;
  cin >> n >> m;
  
  using Job = pair<int, int>;
  using JobQueue = priority_queue<Job, vector<Job>, greater<Job>>;
  JobQueue jobs;
  for (int i = 0; i < n; i++) {
    Job job;
    cin >> job.first >> job.second;
    jobs.push(job);
  }
  
  long long ans = 0;
  priority_queue<int> q2;
  for (int i = 1; i <= m; i++) {
    while (!jobs.empty() && jobs.top().first <= i) {
      q2.push(jobs.top().second);
      jobs.pop();
    }

    if (!q2.empty()) {
      ans += q2.top();
      q2.pop();
    }
  }

  cout << ans << "\n";
  return 0;
}
