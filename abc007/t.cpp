#include <array>
#include <iostream>
#include <vector>

int main(int argc, const char *argv[])
{
  using std::vector;
  using std::array;
  using std::cout;
  vector<array<array<int, 2>, 2>> arr(3);
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[i].size(); j++) {
      for (int k = 0; k < 2; k++) {
        cout << arr[i][j][k] << " ";
      }
    }

    cout << "\n";
  }
  
  
  return 0;
}
