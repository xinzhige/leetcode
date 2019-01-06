// Idea: go through nums and build a hash table with current numbers
// as keys and next greater numbers as values.
// Time: O(m+n).
class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    vector<int> result;
    stack<int> st;
    unordered_map<int, int> next;
    for (const auto &num : nums) {
      while (!st.empty() && st.top() < num) {
        next[st.top()] = num;
        st.pop();
      }
      st.emplace(num);
    }
    for (const auto &elem : findNums) {
      int tmp = (next.count(elem) == 0 ? -1 : next[elem]);
      result.emplace_back(tmp);
    }
    return result;
  }
};
