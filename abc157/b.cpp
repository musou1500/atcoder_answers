#include <iostream>
#include <array>
#include <vector>

using namespace std;

struct Cell {
  int val;
  bool checked;
  Cell() : checked(false), val(0) {};
};


bool checkDiagonally(array<array<Cell, 3>, 3> tbl, int dir) {
  bool matched = true;
  int yi = 0, xi = dir == 1 ? 0 : 2; 
  while (yi < 3 && xi < 3 && xi >= 0) {
    if (!tbl[yi][xi].checked) {
      matched = false;
      break;
    }
    yi++;
    xi += dir;
  }

  return matched;
}

// 横にチェック
bool checkHorizontally(array<array<Cell, 3>, 3> tbl, int x, int y) {
  bool matched = true;
  for (int xi = 0; xi < 3; xi++) {
    if (!tbl[y][xi].checked) {
      matched = false;
      break;
    }
  }

  return matched;
}

// 縦にチェック
bool checkVertically(array<array<Cell, 3>, 3> tbl, int x, int y) {
  bool matched = true;
  for (int yi = 0; yi < 3; yi++) {
    if (!tbl[yi][x].checked) {
      matched = false;
      break;
    }
  }

  return matched;
}

int main(int argc, const char *argv[])
{
  array<array<Cell, 3>, 3> tbl;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> tbl[i][j].val;
    }
  }

  int n;
  cin >> n;
  bool matched = false;
  for (int i = 0; i < n; i++) {
    int num, x = -1, y = -1;
    cin >> num;

    // 指定された数字を探す
    for (int xi = 0; xi < 3; xi ++) {
      for (int yi = 0; yi < 3; yi++) {
        if (tbl[yi][xi].val == num && !tbl[yi][xi].checked) {
          tbl[yi][xi].checked = true;
          x = xi;
          y = yi;
          break;
        }
      }
    }

    if (x == -1 || y == -1) {
      continue;
    }

    // 指定された数字があった
    // 同じ行，列の検査
    bool hmatch = checkHorizontally(tbl, x, y);
    if (checkHorizontally(tbl, x, y) || checkVertically(tbl, x, y)) {
      matched = true;
      break;
    }

    // 対角線上にある場合，斜めに検査
    // y = x
    // y = 3 - x + 1
    if (checkDiagonally(tbl, 1) || checkDiagonally(tbl, -1)) {
      matched = true;
      break;
    }
  }

  cout << (matched ? "Yes" : "No") << "\n";

  return 0;
}
