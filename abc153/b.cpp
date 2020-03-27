#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  int h, n;
  cin >> h >> n;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    int n;
    cin >> n;
    sum += n;
  }

  if (h <= sum) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  
  return 0;
}
