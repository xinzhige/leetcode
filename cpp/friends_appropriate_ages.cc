class Solution {
public:
  int numFriendRequests(vector<int>& ages) {
    vector<int> count(121, 0);
    for (const auto &age : ages) {
      count[age] += 1;
    }
    int result = 0;
    for (int i = 0; i <= 120; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (j > i * 0.5 + 7) {
          result += count[i] * count[j];
          if (i == j) {
            result -= count[i];
          }
        }
      }
    }
    return result;
  }
};
