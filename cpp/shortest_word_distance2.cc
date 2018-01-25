class WordDistance {
public:
  WordDistance(vector<string> words) {
    for (auto i = 0; i < words.size(); ++i) {
      wordIndex[words[i]].emplace_back(i);
    }
  }

  int shortest(string word1, string word2) {
    const auto& indexes1 = wordIndex[word1];
    const auto& indexes2 = wordIndex[word2];
    auto i = 0;
    auto j = 0;
    auto dist = INT_MAX;
    while (i < indexes1.size() && j < indexes2.size()) {
      dist = min(dist, abs(indexes1[i] - indexes2[j]));
      indexes1[i] < indexes2[j] ? ++i : ++j;
    }
    return dist;
  }

private:
  unordered_map<string, vector<int>> wordIndex;
};
