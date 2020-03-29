#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  int n, x, y;
  cin >> n >> x >> y;
  
  vector<int> dists(n, 0);

  for (int i = 1; i <= n - 1; i++) {
    for (int j = i + 1; j <= n; j++) {
      int dist = j - i;
      dist = min(dist, abs(x - i) + min(j - x, 1 + abs(y - j)));
      dists[dist]++;
    }
  }
  
  for (int i = 1; i <= n - 1; i++) {
    cout << dists[i] << "\n";
  }
  
  return 0;
}
