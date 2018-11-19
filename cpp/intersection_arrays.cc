// use unordered_set time: O(max(m, n)), space O(max(m, n))
class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> mymap(nums1.begin(), nums1.end());
    vector<int> result;
    for (auto &n : nums2) {
      if (mymap.count(n) > 0) {
        result.emplace_back(n);
        mymap.erase(n);
      }
    }
    return result;
  }
};


// sort arrays time O(max(m, n) log(max(m, n))) Space: O(1)
class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0;
    int j = 0;
    vector<int> result;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] == nums2[j]) {
        if (result.size() == 0 || nums1[i] != result.back()) {
          result.emplace_back(nums1[i]);
        }
        ++i;
        ++j;
      } else if (nums1[i] < nums2[j]) {
        ++i;
      } else {
        ++j;
      }
    }
    return result;
  }
};
