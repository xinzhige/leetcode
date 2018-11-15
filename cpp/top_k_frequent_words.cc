class Solution {
public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> freq;
    for (const auto &w : words) {
      freq[w] += 1;
    }
    priority_queue<pair<string, int>, vector<pair<string, int>>,
                   Comparator> pq;
    for (const auto &w : freq) {
      pq.emplace(w.first, w.second);
      if (pq.size() > k) {
        pq.pop();
      }
    }
    vector<string> result(k);
    for (int i = k - 1; i >= 0; --i) {
      result[i] = pq.top().first;
      pq.pop();
    }
    return result;
  }

private:
  struct Comparator {
    bool operator() (pair<string, int> &word1, pair<string, int> &word2) {
      return word1.second > word2.second ||
        (word1.second == word2.second && word1.first < word2.first);
    }
  };
};
