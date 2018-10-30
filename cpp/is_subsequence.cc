class Solution {
public:
  bool isSubsequence(string s, string t) {
    if (s.size() == 0) {
      return true;
    }
    int i = 0;
    for (int j = 0; j < t.size(); ++j) {
      if (t[j] == s[i]) {
        ++i;
        if (i == s.size()) {
          return true;
        }
      }
    }
    return false;
  }
};


// Follow-up
class Solution {
public:
  bool isSubsequence(string s, string t) {
    unordered_map<char, vector<int>> index;
    for (int i = 0; i < t.size(); ++i) {
      if (index.count(t[i]) == 0) {
        vector<int> curr;
        index[t[i]] = curr;
      }
      index[t[i]].push_back(i);
    }
    int prev = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (index.count(s[i]) == 0) {
        return false;
      }
      int j = binarySearch(index[s[i]], prev);
      if (j < 0) {
        j = -j - 1;
      }
      if (j == index[s[i]].size()) {
        return false;
      }
      prev = index[s[i]][j] + 1;
    }
    return true;
  }
  int binarySearch(vector<int> &nums, int x) {
    int begin = 0;
    int end = nums.size() - 1;
    int mid = 0;
    while (begin <= end) {
      mid = begin + (end - begin) / 2;
      if (nums[mid] == x) {
        return i;
      } else if (nums[mid] < x) {
        begin = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return -1;
  }
};
