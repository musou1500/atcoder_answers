#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  int cnt = 0;
  for (int i = 1; i < p.size() - 1; i++) {
    if (p[i - 1] < p[i] && p[i] < p[i + 1]) {
      cnt++;
    } else if (p[i - 1] > p[i] && p[i] > p[i + 1]) {
      cnt++;
    } else if (p[i - 1] == p[i + 1] && p[i] > p[i - 1]) {
      cnt++;
    }
  }

  cout << cnt << "\n";
}

