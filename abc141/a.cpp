#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[]) {
  string s;
  cin >> s;
  if (s == "Sunny") {
    cout << "Cloudy\n";
  } else if (s == "Cloudy") {
    cout << "Rainy\n";
  } else {
    cout << "Sunny\n";
  }

  return 0;
}
