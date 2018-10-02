class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> result;
    unordered_map<int, int> idx;
    for(int i = 0; i < nums.size(); ++i) {
      int gap = target - nums[i];
      if(idx.count(gap) > 0) {
        result.emplace_back(idx[gap]);
        result.emplace_back(i);
        break;
      } else {
        idx[nums[i]] = i;
      }
    }
    return result;
  }
};
