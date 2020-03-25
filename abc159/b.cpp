#include <iostream>
#include <iterator>

using namespace std;

bool is_palindrome(string::const_iterator begin, const string::const_iterator end) {
  int len = distance(begin, end);
  for (int i = 0; i < len / 2; i++) {
    if (*(begin + i) != *(end - i - 1)) {
      return false;
    }
  }

  return true;
}

bool is_strong_palindrome(string &s) {
  return is_palindrome(s.begin(), s.end())
    && is_palindrome(s.begin(), s.begin() + (s.size() - 1) / 2)
    && is_palindrome(s.begin() + (s.size() + 3) / 2 - 1, s.end());
}

int main(int argc, const char *argv[])
{
  string s;
  cin >> s;
  cout << (is_strong_palindrome(s) ? "Yes" : "No") << "\n";
  return 0;
}
