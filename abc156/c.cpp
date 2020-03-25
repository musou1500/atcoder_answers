#include <iostream>
#include <vector>

using namespace std;

int sum(vector<int> &xs, int pos) {
  int sum = 0;
  for (auto x : xs) {
    int base = (x - pos);
    sum += base * base;
  }

  return sum;
}

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;
  vector<int> xs(n);
  for (int i = 0; i < n; i++) {
    cin >> xs[i];
  }

  int min = -1;
  for (int i = 0; i <= 100; i++) {
    int hp_sum = sum(xs, i);
    if (min < 0 || min > hp_sum) {
      min = hp_sum;
    }
  }

  cout << min << "\n";
}
