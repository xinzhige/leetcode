class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    int result = 0;
    int sum = 0;
    unordered_map<int, int> mymap{{0, -1}};
    for (int i = 0; i < nums.size(); ++i) {
      sum += (nums[i] << 1) - 1; 
      if (mymap.find(sum) != mymap.end()) {
        result = max(result, i - mymap[sum]); 
      } else {
        mymap[sum] = i; 
      }
    }
    return result;
  }
};
