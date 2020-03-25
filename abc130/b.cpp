#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  int n, x;
  cin >> n >> x;

  vector<int> ls(n);
  for (int i = 0; i < n; i++) {
    cin >> ls[i];
  }

  int d = 0, cnt = 1;
  for (int i = 0; i < n; i++) {
    d = d + ls[i];
    if (d > x) {
      break;
    }

    cnt++;
  }

  cout << cnt << "\n";
}
