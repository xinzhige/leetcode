class Solution {
public:
  int maxDistToClosest(vector<int>& seats) {
    int n = seats.size();
    int emptyGap = 0;
    int result = 0;
    for (int i = 0; i < n; ++i) {
      if (seats[i] == 1) {
        emptyGap = 0;
      } else {
        emptyGap += 1;
        result = max(result, (emptyGap + 1) / 2);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (seats[i] == 1) {
        result = max(result, i);
        break;
      }
    }
    for (int i = n - 1; i >= 0; --i) {
      if (seats[i] == 1) {
        result = max(result, n - 1 - i);
        break;
      }
    }
    return result;
  }
};
