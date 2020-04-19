#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;
  vector<int> va(n - 1);
  for (int i = 0; i < n - 1; i++) {
    cin >> va[i];
    va[i]--;
  }

  vector<int> cnts(n, 0);
  for (int i = 0; i < va.size(); i++) {
    cnts[va[i]]++;
  }

  for (int i = 0; i < cnts.size(); i++) {
    cout << cnts[i] << '\n';
  }

  return 0;
}
