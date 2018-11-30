// Idea: hash-table to store the frequency of each element in the shorter array.
// Time: O(max(m, n)), space O(min(m, n)).
class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
      return intersect(nums2, nums1);
    }
    unordered_map<int, int> freq;
    vector<int> result;
    for (const int &n : nums1) {
      freq[n] += 1;
    }
    for (const int &n : nums2) {
      if (freq.count(n) > 0 && freq[n] > 0) {
        result.push_back(n);
        freq[n] -= 1;
        if (freq[n] == 0) {
          freq.erase(n);
        }
      }
    }
    return result;
  }
};


// Sort arrays time O(max(m, n)logmax(m, n)), space O(1)
class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0;
    int j = 0;
    vector<int> result;
    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] == nums2[j]) {
        result.emplace_back(nums1[i]);
        i += 1;
        j += 1;
      } else if (nums1[i] < nums2[j]) {
        i += 1;
      } else {
        j += 1;
      }
    }
    return result;
  }
};
