#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool distance_is_int(vector<int> a, vector<int> b) {
  int sum = 0;
  for (int i = 0; i < a.size(); i++) {
    int t = a[i] - b[i];
    sum += t * t;
  }

  double distance = sqrt(sum);
  return distance - floor(distance) == 0;
}

int main(int argc, const char *argv[])
{
  int n, d;
  cin >> n >> d;

  vector<vector<int>> coords(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < d; j++) {
      int x;
      cin >> x;
      coords[i].push_back(x);
    }
  }

  int cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      bool is_int = distance_is_int(coords[i], coords[j]);
      if (is_int) {
        cnt++;
      }
    }
  }

  cout << cnt << "\n";
}
