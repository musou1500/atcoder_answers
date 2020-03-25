#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  
  // ボールを入れる箱番号
  set<int> boxes;
  for (int i = n - 1; i >= 0; i--) {
    int cnt = 0;
    if (!boxes.empty()) {
      for (int j = (i + 1) * 2; j <= *boxes.rbegin(); j += i + 1) {
        if (boxes.count(j) == 1) {
          cnt++;
        }
      }
    }

    if (v[i] != cnt % 2) {
      boxes.insert(i + 1);
    }
  }

  cout << boxes.size() << "\n";
  for (auto box : boxes) {
    cout << box << "\n";
  }
  
  return 0;
}
