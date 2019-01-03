class Solution {
public:
  int kEmptySlots(vector<int>& flowers, int k) {
    int result = INT_MAX;
    int left = 0;
    int right = k + 1;
    int n = flowers.size();
    vector<int> days(n , 0);
    for (int i = 0; i < n; ++i) {
      days[flowers[i] - 1] = i + 1;
    }
    int i = 0;
    while (right < n) {
      bool inside = false;
      for (int i = left + 1; i < right; ++i) {
        if (days[i] < days[left] || days[i] < days[right]) {
          left = i;
          right = i + k + 1;
          inside = true;
        }
      }
      if (inside) {
        continue;
      } else {
        result = min(result, max(days[left], days[right]));
        left = right;
        right = left + k + 1;
      }
    }
    return result == INT_MAX ? -1 : result;
  }
};
