#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;

  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  
  sort(d.begin(), d.end());
  int mid = d.size() / 2;
  int result = d[mid] - d[mid - 1];
  cout << result << "\n";

  return 0;
}

