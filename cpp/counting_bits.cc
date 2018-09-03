// Time: O(n*sizeof(integer)), space: O(n)
class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> result(num + 1, 0);
    for (int i = 1; i <= num; ++i) {
      result[i] = count(i);
    }
    return result;
  }

  int count(int num) {
    int result = 0;
    for (; num > 0; num &= num - 1) {
      result += 1;
    }
    return result;
  }
};


// Time: O(n), space: O(n)
class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> result(num + 1, 0);
    for (int i = 1; i <= num; ++i) {
      result[i] = result[i & (i - 1)] + 1;
    }
    return result;
  }
};
