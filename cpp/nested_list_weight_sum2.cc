class Solution {
public:
  int depthSumInverse(vector<NestedInteger>& nestedList) {
    int weighted = 0;
    int unweighted = 0;
    while (!nestedList.empty()) {
      vector<NestedInteger> next;
      for (auto curr : nestedList) {
        if (curr.isInteger()) {
          unweighted += curr.getInteger();
        } else {
          next.insert(next.end(), curr.getList().begin(), curr.getList().end());
        }
      }
      weighted += unweighted;
      nestedList = next;
    }
    return weighted;
  }
};
