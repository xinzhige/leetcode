// Bitset
class Solution {
public:
  vector<string> readBinaryWatch(int num) {
    vector<string> result;
    if (num >= 0 && num <= 10) {
      for (int h = 0; h < 12; h++) {
        for (int m = 0; m < 60; m++) {
          bitset<10> curr_bits(h << 6 | m);
          if (curr_bits.count() == num) {
            result.push_back(to_string(h) + (m < 10 ? ":0" : ":") +
                                to_string(m));
          }
        }
      }
    }
    return result;
  }
};


// Backtracking
class Solution {
public:
  vector<string> readBinaryWatch(int num) {
    vector<string> result;
    if (num >= 0 && num <= 10) {
      vector<int> hour{8, 4, 2, 1};
      vector<int> minute{32, 16, 8, 4, 2, 1};
      for (int i = 0; i <= num; ++i) {
        vector<int> hours = generate(hour, i);
        vector<int> minutes = generate(minute, num - i);
        for (const auto &h : hours) {
          if (h < 12) {
            for (const auto &m : minutes) {
              if (m < 60) {
                result.push_back(to_string(h) + (m < 10 ? ":0" : ":") +
                                 to_string(m));
              }
            }
          }
        }
      }
    }
    return result;
  }
  vector<int> generate(vector<int>& nums, int count) {
    vector<int> result;
    helper(nums, count, 0, 0, result);
    return result;
  }
  void helper(vector<int>& nums, int count, int pos, int out,
              vector<int>& result) {
    if (count == 0) {
      result.push_back(out);
      return;
    }
    for (int i = pos; i < nums.size(); ++i) {
      helper(nums, count - 1, i + 1, out + nums[i], result);
    }
  }
};
