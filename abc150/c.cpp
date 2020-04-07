#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, const char *argv[]) {
  int n;
  cin >> n;

  vector<int> p(n), q(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> q[i];
  }

  vector<int> perm(n);
  iota(perm.begin(), perm.end(), 1);
  int i = 0, p_order, q_order;
  do {
    bool eq_p = equal(perm.begin(), perm.end(), p.begin());
    bool eq_q = equal(perm.begin(), perm.end(), q.begin());
    if (eq_p) {
      p_order = i;
    }
    if (eq_q) {
      q_order = i;
    }

    i++;
  } while (next_permutation(perm.begin(), perm.end()));

  cout << abs(p_order - q_order) << "\n";
  return 0;
}
