// Idea: sliding window, time: O(l1 + 26 * (l2 - l1))
class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int s1_len = s1.size();
    if (s1_len > s2.size()) {
      return false;
    }
    vector<int> freq(26, 0);
    for (int i = 0; i < s1_len; ++i) {
      freq[s1[i] - 'a'] += 1;
      freq[s2[i] - 'a'] -= 1;
    }
    if (allZero(freq)) {
      return true;
    }
    // i points to the right side of the sliding window
    for (int i = s1_len; i < s2.size(); ++i) {
      freq[s2[i] - 'a'] -= 1;
      freq[s2[i - s1_len] - 'a'] += 1;
      if (allZero(freq)) {
        return true;
      }
    }
    return false;
  }
  bool allZero(vector<int>& freq) {
    for (const auto &x : freq) {
      if (x != 0) {
        return false;
      }
    }
    return true;
  }
};


// Idea: instead of comparing all the elements of the hash-table each time,
// maintain a variable that stores the number of characters that have the
// same frequency in s1 and the sliding window.
// Time: O(l1 + (l2 - l1))
class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int s1_len = s1.size();
    if (s1_len > s2.size()) {
      return false;
    }
    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);
    for (int i = 0; i < s1_len; ++i) {
      freq1[s1[i] - 'a'] += 1;
      freq2[s2[i] - 'a'] += 1;
    }
    int count = 0;
    for (int i = 0; i < 26; ++i) {
      if (freq1[i] == freq2[i]) {
        count += 1;
      }
    }
    for (int i = 0; i < s2.size() - s1_len; ++i) {
      int left = s2[i] - 'a';
      int right = s2[i + s1_len] - 'a';
      if (count == 26) {
        return true;
      }
      freq2[right] += 1;
      if (freq2[right] == freq1[right]) {
        count += 1;
      } else if (freq2[right] == freq1[right] + 1) {
        count -= 1;
      }
      freq2[left] -= 1;
      if (freq2[left] == freq1[left]) {
        count += 1;
      } else if (freq2[left] == freq1[left] - 1) {
        count -= 1;
      }
    }
    return count == 26;
  }
};
