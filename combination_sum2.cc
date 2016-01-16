class Solution {
public:
  void combinationSumHelper(vector<vector<int> > &result, vector<int> &temp, 
			    vector<int> &nums, int index, int target){
    if (target == 0) {
      result.push_back(temp);
      return;
    }
    int prev = 0;
    for (int i = index; i < nums.size(); ++i) {
      if (prev == nums[i]) {  // skip duplicates, for example, [1,1] and 1
	continue;
      }
      if (target < nums[i]) {
	return;
      }
      prev = nums[i];
      temp.push_back(nums[i]);
      combinationSumHelper(result, temp, nums, i+1, target-nums[i]);
      temp.pop_back();
    }
  }
  vector<vector<int> > combinationSum2(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > result;
    vector<int> temp;
    combinationSumHelper(result, temp, nums, 0, target);
    return result;
  }
};
