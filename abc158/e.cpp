#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

int mods(string s, int n) {
  int result = (s[s.size() - 1] - '0') % n;
  for (int i = s.size() - 2; i >= 0; i--) {
    int num = s[i] - '0';
    result = (result + num) % n;
  }

  return result;
}

int main(int argc, const char *argv[])
{
  long long n, p;
  string s;
  cin >> n >> p >> s;

  if (p == 2 || p == 5) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
      int digit = s[i] - '0';
      if (digit % p == 0) {
        result += s.size() - i;
      }
    }

    cout << result << "\n";
    return 0;
  }
  
  // 累積和
  vector<int> com_sums(n, 0);
  for (int i = s.size() - 1; i >= 0 ; i--) {
    int digit = s[i] - '0';
    if (i == s.size() - 1) {
      com_sums[i] = digit % p;
    } else {
      com_sums[i] = com_sums[i + 1] + digit % p;
    }
  }
  
  int result = 0;
  for (int i = 0; i < com_sums.size(); i++) {
    if (com_sums[i] % p == 0) {
      result++;
    }

    for (int j = i + 1; j < com_sums.size(); j++) {
      if (com_sums[i] == com_sums[j]) {
        cout << i << " " << j << "\n";
        result++;
      }
    }
  }
  cout << result << "\n";
}
