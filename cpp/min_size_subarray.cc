// O(n)
class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int result = INT_MAX;
    int left = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      for (; left <= i && sum >= s; ++left) {
	result = min(result, i - left + 1);
	sum -= nums[left];
      }
    }
    return result == INT_MAX ? 0 : result;
  }
};

// O(nlgn)
class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    // O(n)
class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int result = INT_MAX;
    int left = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      for (; left <= i && sum >= s; ++left) {
	result = min(result, i - left + 1);
	sum -= nums[left];
      }
    }
    return result == INT_MAX ? 0 : result;
  }
};

// O(nlgn)
class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int result = INT_MAX;
    int n = nums.size();
    vector<int> sums(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      sums[i] = sums[i - 1] + nums[i - 1];
    }
    for (int i = 0; i < n; ++i) {
      int left = i + 1;
      int right = n;
      int t = sums[i] + s;
      while (left <= right) {
	int mid = left + (right - left) / 2;
	if (sums[mid] < t) {
	  left = mid + 1;
	} else {
	  right = mid - 1;
	}
      }
      if (left == n + 1) {
	break;
      }
      result = min(result, left - i);
    }
    return result == INT_MAX ? 0 : result;
  }
};
