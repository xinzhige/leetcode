class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    int sum = 0;
    unordered_map<int, int> mymap{{0,-1}};
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      int tmp = (k == 0) ? sum : (sum % k);
      if (mymap.find(tmp) != mymap.end()) {
	if (i - mymap[tmp] > 1) {
	  return true;
	}
      } else {
	mymap[tmp] = i;
      }
    }
    return false;
  }
};
