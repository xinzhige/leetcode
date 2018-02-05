// Time: O(n^2), space: O(1)
class Solution {
public:
  int countSubstrings(string s) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
      extendPalindrome(s, i, i, count);
      extendPalindrome(s, i, i + 1, count);
    }
    return count;
  }
  void extendPalindrome(string s, int left, int right, int& count) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      count += 1;
      left -= 1;
      right += 1;
    }
  }
};

// Manacher's Algorithm
class Solution {
public:
  int countSubstrings(string s) {
    string str(2 * s.size() + 3, ' ');
    str[0] = '@';
    str[1] = '#';
    str[str.size() - 1] = '$';
    int t = 2;
    for (auto &c : s) {
      str[t++] = c;
      str[t++] = '#';
    }
    int center = 0;
    int right = 0;
    vector<int> dist(str.size(), 0);
    for (int i = 1; i < dist.size() - 1; ++i) {
      if (i < right) {
        dist[i] = min(dist[2 * center - i], right - i);
      }
      while (str[i + dist[i] + 1] == str[i - dist[i] - 1]) {
        dist[i] += 1;
      }
      if (i + dist[i] > right) {
        right = i + dist[i];
        center = i;
      }
    }
    int result = 0;
    for (const auto &d : dist) {
      result += (d + 1) / 2;
    }
    return result;
  }
};
