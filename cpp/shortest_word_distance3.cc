class Solution {
public:
  int shortestWordDistance(vector<string>& words, string word1, string word2) {
    // Initialize index1 and index2 to be the values such that the value of
    // dist computed first to be large enough (words length).
    int index1 = words.size();
    int index2 = -words.size();
    int dist = INT_MAX;
    for (auto i = 0; i < words.size(); ++i) {
      if (words[i] == word1) {
        index1 = (word1 == word2 ? index2 : i);
      }
      if (words[i] == word2) {
        index2 = i;
      }
      dist = min(dist, abs(index1 - index2));
    }
    return dist;
  }
};
