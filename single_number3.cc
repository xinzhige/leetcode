class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    vector<int> result(2, 0);
    int last_one = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    last_one &= -last_one;
    for (auto num : nums) {
      if ((num & last_one) == 0) {
        result[0] ^= num;
      } else {
        result[1] ^= num;
      }
    }
    return result;
  }
};
