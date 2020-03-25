#include <array>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
  array<int, 5> arr(-1);
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << "\n";
  }
  
  return 0;
}
