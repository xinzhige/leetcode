class Solution {
public:
  Solution(vector<int> nums) : originals(nums) {}

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() {
    return originals;
  }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    vector<int> result = originals;
    int n = originals.size();
    for (int i = 0; i < n; ++i) {
      int t = i + rand() % (n - i);
      swap(result[i], result[t]);
    }
    return result;
  }
private:
  vector<int> originals;
};
