#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;

  vector<int> cities(n + 1);
  vector<int> savers(n);
  for (int i = 0; i < n + 1; i++) cin >> cities[i];
  for (int i = 0; i < n; i++) cin >> savers[i];
  
  unsigned long long ans = 0;
  auto defeat = [&](int &saver, int &city, int cnt) {
    ans += cnt;
    saver -= cnt;
    city -= cnt;
  };

  for (int i = n - 1; i >= 0; i--) {
    defeat(savers[i], cities[i + 1], min(cities[i + 1], savers[i]));
    defeat(savers[i], cities[i], min(cities[i], savers[i]));
  }

  cout << ans << "\n";
  
  return 0;
}
