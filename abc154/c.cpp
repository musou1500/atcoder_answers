#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;
  vector<int> a;
  set<int> distinct;
  for (int i = 0; i < n; i++) {
    int n;
    cin >> n;
    a.push_back(n);
    distinct.insert(n);
  }

  cout << (a.size() != distinct.size() ? "NO" : "YES") << "\n";
  return 0;
}
