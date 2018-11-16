// Time: O(n^2), space: O(1)
class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int sum = 0;
      for (int j = i; j < nums.size(); ++j) {
        sum += nums[j];
        if (sum == k) {
          result += 1;
        }
      }
    }
    return result;
  }
};



// Time: O(n), space: O(n)
class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mymap;
    int sum = 0;
    int result = 0;
    // In case the result takes the starting point as the first element,
    // for example, in nums=[1, 1, 1] and k=2, when reach the second 1,
    // the map does not have (0, 1) if we do not add.
    mymap[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (mymap.count(sum - k) > 0) {
        result += mymap[sum - k];
      }
      mymap[sum] += 1;
    }
    return result;
  }
};
