class Solution {
public:
  int findMaximumXOR(vector<int>& nums) {
    int mask = 0;
    int result = 0;
    for (int i = 31; i >= 0; --i) {
      mask |= 1 << i;
      unordered_set<int> high_bits;
      for (const auto& num : nums) {
        high_bits.insert(mask & num);
      }
      int tmp = result | (1 << i);
      for (const auto& bits : high_bits) {
        if (high_bits.count(tmp ^ bits)) {
          result = tmp;
          break;
        }
      }
    }
    return result;
  }
};
