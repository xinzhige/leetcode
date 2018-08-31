// DFS
class Solution {
public:
  vector<string> findItinerary(vector<pair<string, string>> tickets) {
    vector<string> result;
    unordered_map<string, multiset<string>> targets;
    for (const auto &t : tickets) {
      targets[t.first].insert(t.second);
    }
    dfs(targets, "JFK", result);
    return vector<string> (result.rbegin(), result.rend());
  }
  void dfs(unordered_map<string, multiset<string>> &targets,
           string s, vector<string> &result) {
    while (!targets[s].empty()) {
      auto t = *(targets[s].begin());
      targets[s].erase(targets[s].begin());
      dfs(targets, t, result);
    }
    result.push_back(s);
  }
};


// Stack
class Solution {
public:
  vector<string> findItinerary(vector<pair<string, string>> tickets) {
    vector<string> result;
    stack<string> mystack{{"JFK"}};
    unordered_map<string, multiset<string>> targets;
    for (const auto &t : tickets) {
      targets[t.first].insert(t.second);
    }
    while (!mystack.empty()) {
      auto t = mystack.top();
      if (targets[t].empty()) {
        result.insert(result.begin(), t);
        mystack.pop();
      } else {
        mystack.push(*(targets[t].begin()));
        targets[t].erase(targets[t].begin());
      }
    }
    return result;
  }
};
