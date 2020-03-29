#include <functional>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;

  priority_queue<double, vector<double>, greater<double>> q;
  for (int i = 0; i < n; i++) {
    double n;
    cin >> n;
    q.push(n);
  }

  while (q.size() > 1) {
    double fst = q.top();
    q.pop();
    double snd = q.top();
    q.pop();
    q.push((fst + snd) / 2);
  }
  
  cout << q.top() << "\n";
  
  return 0;
}
