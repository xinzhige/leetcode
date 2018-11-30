// Idea: sum the two numbers at the begin and end and find their location.
class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int begin = 0;
    int end = numbers.size() - 1;
    vector<int> result;
    while (begin < end) {
      int sum = numbers[begin] + numbers[end];
      if (sum > target) {
        end -= 1;
      } else if (sum < target) {
        begin += 1;
      } else {
        result.push_back(begin + 1);
        result.push_back(end + 1);
        return result;
      }
    }
    return {-1, -1};
  }
};
