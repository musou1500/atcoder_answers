#include <iostream>
#include <array>

using namespace std;

int main(int argc, const char *argv[])
{
  string dow;
  cin >> dow;
  array<string, 7> dows{"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
  for (int i = 0; i < dows.size(); i++) {
    if (dows[i] == dow) {
      cout << dows.size() - i << "\n";
      break;
    }
  }

  return 0;
}
