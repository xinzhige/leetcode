class Solution {
public:
  int threeSumClosest(vector<int> &num, int target) {
    int len = num.size();
    assert(len >= 3);
    sort(num.begin(), num.end());
    int sum = num[0] + num[1] + num[2];
    int diff = abs(sum - target);
    int result = sum;
    for(int i = 0; i < len - 2; ++i) {
      int left = i + 1;
      int right = len - 1;
      while(left < right) {
	sum = num[i] + num[left] + num[right];
	if(sum == target) {
	  return sum;
	} else if (sum < target){
	  ++left;
	} else {
	  --right;
	}
	if(abs(sum - target) < diff) {
	  diff = abs(sum - target);
	  result = sum;
	}
      }
    }
    return result;
  }
};
