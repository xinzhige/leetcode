// Idea: find the longest length of subarrays with at most 2 unique numbers.
class Solution {
public:
  int totalFruit(vector<int>& tree) {
    map<int, int> count;
    int result = 0;
    int i = 0;
    for (int j = 0; j < tree.size(); ++j) {
      count[tree[j]] += 1;
      while (count.size() > 2) {
        count[tree[i]] -= 1;
        if (count[tree[i]] == 0) {
          count.erase(tree[i]);
        }
        ++i;
      }
      result = max(result, j - i + 1);
    }
    return result;
  }
};
