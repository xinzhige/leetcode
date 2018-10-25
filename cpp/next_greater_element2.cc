class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> mystack;
    int n = nums.size();
    vector<int> result(n, -1);
    for (int i = 0; i < 2 * n; ++i) {
      int num = nums[i % n];
      while (!mystack.empty() && nums[mystack.top()] < num) {
        result[mystack.top()] = num;
        mystack.pop();
      }
      if (i < n) {
        mystack.push(i);
      }
    }
    return result;
  }
};
