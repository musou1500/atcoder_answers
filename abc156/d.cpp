#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  // 2 <= n <= 10^9
  int n, a, b;
  cin >> n >> a >> b;
  
  // 分子，分母
  int deno = 1, nume = 1;
  int num_combs = 0;
  for (int i = 1; i <= n; i++) {
    nume *= n - i + 1;
    deno *= i;
    cout << nume << "/" << deno << "\n";
    if (i == a || i == b) {
      continue;
    }

    num_combs += deno / nume;
  }

  cout << num_combs << "\n";
  return 0;
}
