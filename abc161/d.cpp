#include <iostream>
#include <queue>

using namespace std;

using ll = long long;

ll kth_lunlun_number(int k) {
  if (k <= 9) {
    return k;
  }

  queue<ll> q;
  for (int i = 1; i <= 9; i++) {
    q.push(i);
  }

  for (int i = 0; i < k - 1; i++) {
    ll n = q.front();
    q.pop();

    int d = n % 10;
    if (d != 0) {
      q.push(n * 10 + d - 1);
    }

    q.push(n * 10 + d);

    if (d != 9) {
      q.push(n * 10 + d + 1);
    }
  }

  return q.front();
}

int main(int argc, const char *argv[])
{
  int k;
  cin >> k;
  cout << kth_lunlun_number(k);
  return 0;
}
