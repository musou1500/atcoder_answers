#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char *argv[])
{
  vector<int> nums{
    1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51
  };
  int k;
  cin >> k;
  cout << nums[k - 1] << "\n";
  return 0;
}
