// Brute force, time: O(mn)
class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    vector<int> result;
    for (const auto &num : findNums) {
      int i = 0;
      for (; i < nums.size() && nums[i] != num; ++i);
      int j = i + 1;
      for (; j < nums.size() && nums[j] < num; ++j);
      if (j == nums.size()) {
        result.emplace_back(-1);
      } else {
        result.emplace_back(nums[j]);
      }
    }
    return result;
  }
};


// Use stack and unordered_map
class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    vector<int> result;
    stack<int> mystack;
    unordered_map<int, int> next_greater;
    for (const auto &num : nums) {
      while (!mystack.empty() && mystack.top() < num) {
        next_greater[mystack.top()] = num;
        mystack.pop();
      }
      mystack.emplace(num);
    }
    for (const auto &elem : findNums) {
      int tmp = (next_greater.count(elem) > 0 ? -1 : next_greater[elem]);
      result.emplace_back(tmp);
    }
    return result;
  }
};
