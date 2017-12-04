class Solution {
public:
  int depthSum(vector<NestedInteger>& nestedList) {
    return dfs(nestedList, 1);
  }

private:
  int dfs(vector<NestedInteger> curr, int depth) {
    int sum = 0;
    for (auto num : curr) {
      if (num.isInteger()) {
        sum += depth * num.getInteger();
      } else {
        sum += dfs(num.getList(), depth + 1);
      }
    }
    return sum;
  }
};
