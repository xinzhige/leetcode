// Idea: fill out the most frequent letter to the least one, use max heap
// to store all the (frequency, letter) pairs and each time reduce the
// frequency of top by 1.
class Solution {
public:
  string rearrangeString(string s, int k) {
    if (k < 2) {
      return s;
    }
    int n = s.size();
    unordered_map<char, int> freq;
    priority_queue<pair<int, char>> pq;
    for (const char &c : s) {
      freq[c] += 1;
    }
    for (const auto &p : freq) {
      pq.emplace(p->second, p->first);
    }
    string result("");
    while (!pq.empty()) {
      vector<pari<int, char>> cache;
      int count = min(k, n);
      for (int i = 0; i < count; ++i) {
        if (pq.empty()) {
          return "";
        }
        auto temp = pq.top();
        pq.pop();
        result.push_back(temp.second);
        temp.first -= 1;
        if (temp.first > 0) {
          cache.push_back(temp);
        }
        --n;
      }
      for (const auto &p : cache) {
        pq.push(p);
      }
    }
    return result;
  }
};
