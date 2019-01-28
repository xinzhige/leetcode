class Solution {
public:
  int strobogrammaticInRange(string low, string high) {
    int result = 0;
    find(low, high, "", result);
    find(low, high, "0", result);
    find(low, high, "1", result);
    find(low, high, "8", result);
    return result;
  }
  void find(string low, string high, string w, int &result) {
    if (low.size() <= w.size() && w.size() <= high.size()) {
      if (w.size() == high.size() && w.compare(high) > 0) {
        return;
      }
      // skip the numbers that starts from 0 and
      // the numbers that has the same length as low but smaller than low
      if ((w.size() <= 1 || w[0] != '0') &&
          (w.size() > low.size() || w.compare(low) >= 0)) {
        result += 1;
      }
    }
    if (w.size() + 2 <= high.size()) {
      find(low, high, "0" + w + "0", result);
      find(low, high, "1" + w + "1", result);
      find(low, high, "6" + w + "9", result);
      find(low, high, "8" + w + "8", result);
      find(low, high, "9" + w + "6", result);
    }
  }
};
