#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;
  vector<int> hs(n);
  for (int i = 0; i < n; i++) {
    cin >> hs[i];
  }

  int ans = 0, cnt = 0, i = 0;
  while (i < hs.size() - 1) {
    if (hs[i] >= hs[i + 1]) {
      cnt++;
    } else {
      ans = max(ans, cnt);
      cnt = 0;
    }

    i++;
  }

  cout << max(ans, cnt) << "\n";
  
}
