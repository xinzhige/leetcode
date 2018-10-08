class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int result = 0;
    int curr = 0;
    int count = 0;
    for (const auto &num : nums) {
      count += 1;
      if (num == 0) {
        curr = count;
        count = 0;
      }
      result = max(result, count + curr);
    }
    return result;
  }
};


// Flip at most k times
class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int result = 0;
    int zeros = 0;
    int left = 0;
    int k = 1;
    for (int right = 0; right < nums.size(); ++right) {
      if (nums[right] == 0) {
        zeros += 1;
      }
      if (zeros > k) {
        if (nums[left] == 0) {
          zeros--;
        }
        left++;
      }
      result = max(result, right - left + 1);
    }
    return result;
  }
};


// Stream
class Solution {
public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int result = 0;
    int left = 0;
    int k = 1;
    queue<int> q;
    for (int right = 0; right < nums.size(); ++right) {
      if (nums[right] == 0) {
        q.push(right);
      }
      if (q.size() > k) {
        left = q.front() + 1;
        q.pop();
      }
      result = max(result, right - left + 1);
    }
    return result;
  }
};
