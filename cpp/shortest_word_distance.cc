class Solution {
public:
  int shortestDistance(vector<string>& words, string word1, string word2) {
    auto dist = INT_MAX;
    auto index1 = -1;
    auto index2 = -1;
    for (auto i = 0; i < words.size(); ++i) {
      if (words[i] == word1) {
        index1 = i;
      }
      if (words[i] == word2) {
        index2 = i;
      }
      if (index1 != -1 && index2 != -1) {
        dist = min(dist, abs(index1 - index2));
      }
    }
    return dist;
  }
};
