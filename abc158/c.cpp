#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[])
{
  int a, b;
  cin >> a >> b;

  int result = -1;
  for (int i = 0; i <= 1000; i++) {
    if ((int)(i * 0.08) == a && (int)(i * 0.1) == b) {
      result = i;
      break;
    }
  }

  cout << result << "\n";
}
