// Binary index tree
class NumArray {
public:
  NumArray(vector<int> nums) {
    num.resize(nums.size() + 1);
    bit.resize(nums.size() + 1);
    for (int i = 0; i < nums.size(); ++i) {
      update(i, nums[i]);
    }
  }
  void update(int i, int val) {
    int diff = val - num[i + 1];
    for (int j = i + 1; j < num.size(); j += (j&(-j))) {
      bit[j] += diff;
    }
    num[i + 1] = val;
  }
  int sumRange(int i, int j) {
    return getSum(j + 1) - getSum(i);
  }
  int getSum(int i) {
    int res = 0;
    for (int j = i; j > 0; j -= (j&(-j))) {
      res += bit[j];
    }
    return res;
  }

private:
  vector<int> num;
  vector<int> bit;
};


// Segment tree
class NumArray {
public:
  NumArray(vector<int> nums) {
    if (nums.size() > 0) {
      n = nums.size();
      tree.resize(n * 2);
      buildTree(nums);
    }
  }

  void update(int i, int val) {
    i += n;
    tree[i] = val;
    while (i > 0) {
      int left = i;
      int right = i;
      if (i % 2 == 0) {
        right = i + 1;
      } else {
        left = i - 1;
      }
      tree[i / 2] = tree[left] + tree[right];
      i /= 2;
    }
  }

  int sumRange(int i, int j) {
    i += n;
    j += n;
    int sum = 0;
    while (i <= j) {
      if ((i % 2) == 1) {
        sum += tree[i];
        i++;
      }
      if ((j % 2) == 0) {
        sum += tree[j];
        j--;
      }
      i /= 2;
      j /= 2;
    }
    return sum;
  }

private:
  vector<int> tree;
  int n;
  void buildTree(const vector<int> &nums) {
    for (int i = n, j = 0;  i < 2 * n; ++i, ++j) {
      tree[i] = nums[j];
    }
    for (int i = n - 1; i > 0; --i) {
      tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
  }
};
