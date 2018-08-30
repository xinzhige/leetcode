class Solution {
public:
  bool isValidSerialization(string preorder) {
    preorder += ',';
    int diff = 1;
    for (int i = 0; i < preorder.size(); ++i) {
      if (preorder[i] == ',') {
        diff -= 1;
        if (diff < 0) {
          return false;
        }
        if (preorder[i-1] != '#') {
          diff += 2;
        }
      }
    }
    return diff == 0;
  }
};
