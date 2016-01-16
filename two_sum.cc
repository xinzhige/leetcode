// O(n^2)
class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> my_vec;
    int numbers_size = numbers.size();
    for (int i = 0; i < numbers_size-1; i++) {
      int diff = target - numbers[i];
      my_vec.push_back(i+1);
      for (int j = i+1; j < numbers_size; j++) {
	if (diff == numbers[j]) {
	  my_vec.push_back(j+1);
	  return my_vec;
	}
      }
      my_vec.pop_back();
    }
    return my_vec;
  }
};

// O(n) suppose it is O(1) operation in a hash table
class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> result;
    unordered_map<int, int> my_map;
    for(int i = 0; i < numbers.size(); ++i) {
      int gap = target-numbers[i];
      if(my_map.find(gap) != my_map.end()) {
	result.push_back(my_map[gap]);
	result.push_back(i+1);
      } else {
	my_map[numbers[i]]=i+1;
      }
    }
    return result;
  }
};
