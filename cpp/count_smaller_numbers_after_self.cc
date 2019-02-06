/*
 * Idea: binary indexed tree, use index of element in the sorted array as that
 * in the tree. Then, from the end of original array to update the BIT.
 * Note that current result[i]=sum(nums[i]-1).
 */
class Solution {
public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> result = nums;
    unordered_map<int, int> index;
    int n = nums.size();
    tree.resize(n + 1);
    sort(result.begin(), result.end());
    for (int i = 0; i < n; ++i) {
      index[result[i]] = i + 1;
    }
    for (int i = n - 1; i >= 0; --i) {
      result[i] = sum(index[nums[i]] - 1);
      update(index[nums[i]], 1);
    }
    return result;
  }
private:
  vector<int> tree;
  inline int lowbit(int i) {
    return i & -i;
  }
  void update(int i, int val) {
    int n = tree.size();
    for (; i < n; i += lowbit(i)) {
      tree[i] += val;
    }
  }
  int sum(int i) {
    int result = 0;
    for (; i > 0; i -= lowbit(i)) {
      result += tree[i];
    }
    return result;
  }
};
