// Idea: find the next number to add.
// Case 1: current -> 10*current, 45 -> 450 <= n = 600
// Case 2: current -> current + 1, 45 -> 46 <= n = 60
// Case 3: current -> current / 10^i, 499 -> 5, n = 600
class Solution {
public:
  vector<int> lexicalOrder(int n) {
    vector<int> result;
    int curr = 1;
    for (int i = 1; i <= n; i++) {
      result.emplace_back(curr);
      if (curr * 10 <= n) {
        curr *= 10;
      } else if (curr % 10 != 9 && curr + 1 <= n) {
        curr += 1;
      } else {
        for (; (curr / 10) % 10 == 9; curr /= 10);
        curr = curr / 10 + 1;
      }
    }
    return result;
  }
};
