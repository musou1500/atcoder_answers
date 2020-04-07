#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n, k, r, s, p;
  string t;
  cin >> n >> k >> r >> s >> p >> t;

  int ans = 0;
  vector<bool> results(t.size());
  for (int i = 0; i < t.size(); i++) {
    if (i >= k && t[i - k] == t[i] && results[i - k]) {
      results[i] = false;
      continue;
    }

    results[i] = true;
    switch (t[i]) {
      case 'r':
        ans += p;
        break;
      case 's':
        ans += r;
        break;
      default:
        ans += s;
        break;
    }
  }

  cout << ans << "\n";

  return 0;
}
