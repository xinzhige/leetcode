class Solution {
public:
  bool validUtf8(vector<int>& data) {
    int count = 0;
    for (const auto &c : data) {
      if (count == 0) {
        if ((c >> 5) == 0b110) {
          count = 1;
        } else if ((c >> 4) == 0b1110) {
          count = 2;
        } else if ((c >> 3) == 0b11110) {
          count = 3;
        } else if ((c >> 7) != 0b0) {
          return false;
        }
      } else {
        if ((c >> 6) != 0b10) {
          return false;
        }
        count -= 1;
      }
    }
    return count == 0;
  }
};
