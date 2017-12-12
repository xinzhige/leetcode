class Solution {
public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    int low = 0;
    int high = letters.size();
    while (low < high) {
      int mid = low + (high - low) / 2;
      if (letters[mid] <= target) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return letters[low % letters.size()];
  }
};
