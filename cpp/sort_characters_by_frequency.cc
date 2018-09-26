// Heap
class Solution {
public:
  string frequencySort(string s) {
    string result("");
    unordered_map<char, int> count;
    priority_queue<pair<int, char>> q;
    for (const auto &c : s) {
      count[c] += 1;
    }
    for (const auto &a : count) {
      q.emplace(a.second, a.first);
    }
    for (; !q.empty(); q.pop()) {
      auto curr = q.top();
      result.append(curr.first, curr.second);
    }
    return result;
  }
};


// Array
class Solution {
public:
  string frequencySort(string s) {
    string result("");
    vector<string> freq(s.size() + 1, "");
    unordered_map<char, int> count;
    for (const auto &c : s) {
      count[c] += 1;
    }
    for (const auto &a : count) {
      freq[a.second].append(a.second, a.first);
    }
    for (auto it = freq.rbegin(); it != freq.rend(); ++it) {
      if (!(*it).empty()) {
        result.append(*it);
      }
    }
    return result;
  }
};
