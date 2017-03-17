iclass Solution {
public:
  Solution(vector<int> nums): myarray(nums) {}
    
  int pick(int target) {
    int count = 0;
    int result = -1;
    for (int i = 0; i < myarray.size(); ++i) {
      if (myarray[i] == target) {
	count += 1;
	if (rand() % count == 0) {
	  result = i;
	}
      }
    }
    return result;
  }

private:
    vector<int> myarray;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
