#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> gen(int n, char max_ch, string acc) {
  vector<string> result;
  if (n == 1) {
    for (char c = 'a'; c <= max_ch + 1; c++) {
      result.push_back(acc + c); 
    }
    return result;
  } else {
    for (char c = 'a'; c <= max_ch + 1; c++) {
      auto strs = gen(n - 1, max(max_ch, c), acc + c);
      for (auto s : strs) {
        result.push_back(s);
      }
    }

    return result;
  }
  
}

int main(int argc, const char *argv[])
{
  int n;
  cin >> n;
  if (n == 1) {
    cout << "a\n";
    return 0;
  }

  auto strs = gen(n - 1, 'a', "a");
  for (auto s : strs) {
    cout << s << "\n";
  }
  
  return 0;
}
