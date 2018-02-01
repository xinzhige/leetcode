class Solution {
public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if (maxChoosableInteger >= desiredTotal) {
      return true;
    }
    if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) {
      return false;
    }
    unordered_map<int, bool> winmap;
    return canWin(maxChoosableInteger, desiredTotal, 0, winmap);
  }
  bool canWin(int length, int total, int used,
              unordered_map<int, bool>& winmap) {
    if (winmap.count(used) > 0) {
      return winmap[used];
    }
    for (int i = 0; i < length; ++i) {
      int curr = (1 << i);
      if ((curr & used) == 0) {
        if (total <= i + 1 ||
            !canWin(length, total - (i + 1), curr | used, winmap)) {
          winmap[used] = true;
          return true;
        }
      }
    }
    winmap[used] = false;
    return false;
  }
};
