class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int total = 0;
    int sum = 0;
    int j = -1;
    int len = gas.size();
    int diff = 0;
    for (int i = 0; i < len; ++i) {
      diff = gas[i] - cost[i];
      sum += diff;
      total += diff;
      if (sum < 0) {
        j = i;
        sum = 0;
      }
    }
    return total >= 0 ? j + 1 : -1;
  }
};
