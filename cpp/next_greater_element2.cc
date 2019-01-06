// Idea: store indices in stack because there might be duplicates.
// Note: traverse the new array: nums + nums and use % to find index.
class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> st;
    int n = nums.size();
    vector<int> result(n, -1);
    for (int i = 0; i < 2 * n; ++i) {
      int num = nums[i % n];
      while (!st.empty() && nums[st.top()] < num) {
        result[st.top()] = num;
        st.pop();
      }
      if (i < n) {
        st.push(i);
      }
    }
    return result;
  }
};
