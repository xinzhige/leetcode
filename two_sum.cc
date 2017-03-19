class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> result;
    unordered_map<int, int> mymap;
    for(int i = 0; i < numbers.size(); ++i) {
      int gap = target - numbers[i];
      if(mymap.find(gap) != mymap.end()) {
	result.emplace_back(mymap[gap]);
	result.emplace_back(i);
      } else {
	mymap[numbers[i]] = i;
      }
    }
    return result;
  }
};
