#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  string o, e;
  cin >> o >> e;

  string result;
  for (int i = 0; i < o.size() + e.size(); ++i) {
    if (i % 2 == 0) {
      result += o[i / 2];
    } else {
      result += e[(i - 1) / 2];
    }
  }

  cout << result << '\n';
  return 0;
}
