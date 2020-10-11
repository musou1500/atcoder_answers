#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<unsigned long long> lucas(n + 1);
  lucas[0] = 2ull;
  lucas[1] = 1ull;
  for (int i = 2; i < lucas.size(); ++i) {
    lucas[i] = lucas[i - 1] + lucas[i - 2];
  }

  cout << lucas[n] << '\n';
  return 0;
}
