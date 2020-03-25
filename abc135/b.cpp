#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;

  vector<int> p(n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    if (p[i] != i + 1) {
      cnt++;
    }
  }

  cout << (cnt > 2 ? "NO\n" : "YES\n");
  return 0;
}
