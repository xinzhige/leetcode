class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq;
    for (int i = 0; i < nums.size(); ++i) {
      // delete smaller numbers in range k because they are useless
      while (!dq.empty() && nums[dq.back()] <= nums[i]) {
        dq.pop_back();
      }
      dq.push_back(i);
      if (i >= k - 1) {
        result.push_back(nums[dq.front()]);
      }
      // delete numbers out of range k
      if (i - dq.front() + 1 >= k) {
        dq.pop_front();
      }
    }
    return result;
  }
};
