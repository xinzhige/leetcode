class Solution {
public:
  string alienOrder(vector<string>& words) {
    if (words.empty()) {
      return "";
    }
    unordered_map<char, int> indegree;
    unordered_map<char, unordered_set<char>> graph;
    // initialize
    for (const string &word : words) {
      for (const char &c : word) {
        indegree[c] = 0;
      }
    }
    // build graph and record indegree
    for (int i = 0; i < words.size() - 1; ++i) {
      string cur = words[i];
      string nex = words[i + 1];
      int len = min(cur.size(), nex.size());
      for (int j = 0; j < len; ++j) {
        if (cur[j] != nex[j]) {
          unordered_set<char> nodes = graph[cur[j]];
          if (nodes.count(nex[j]) == 0) {
            graph[cur[j]].insert(nex[j]);
            indegree[nex[j]] += 1;
          }
          // If previous corresponding pair of letter are not same, then
          // it is impossible to determine the order of current pair. For
          // example, in "wrta" and "wrfb", "a" and "b" can't be decided.
          // Therefore, here needs break.
          break;
        }
      }
    }
    // topoligical sort
    string ans;
    queue<char> q;
    for (const auto& e : indegree) {
      if (e.second == 0) {
        q.push(e.first);
      }
    }
    while(!q.empty()) {
      char cur = q.front();
      q.pop();
      ans += cur;
      if (!graph[cur].empty()) {
        for (const auto& e : graph[cur]) {
          indegree[e] -= 1;
          if (indegree[e] == 0) {
            q.push(e);
          }
        }
      }
    }
    // tell if it is cyclic
    return ans.length() == indegree.size() ? ans : "";
  }
};
