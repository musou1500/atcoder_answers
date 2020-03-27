#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main(int argc, const char *argv[])
{
  int n;

  // 爆弾の範囲: [x - d, x + d]
  // 威力: a
  ll d, a;
  cin >> n >> d >> a;
  vector<pair<ll, ll>> monsters;
  for (auto m : monsters) {
    // 座標，体力
    cin >> m.first >> m.second;
  }
  
  return 0;
}
