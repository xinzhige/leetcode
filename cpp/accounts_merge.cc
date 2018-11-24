// Idea: construct graph, nodes are emails and emails belong to the same user
// have links. Then BFS the graph from every node.
// Trick1: use hash-table, keys are emails and values are accounts.
// Trick2: use set to store all the emails belong to the same user.
class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    vector<vector<string>> result;
    int n = accounts.size();
    unordered_map<string, vector<int>> email2name;
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j < accounts[i].size(); ++j) {
        email2name[accounts[i][j]].push_back(i);
      }
    }
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
      if (visited[i] == 0) {
        queue<int> q;
        q.push(i);
        set<string> myset;
        while (!q.empty()) {
          int t = q.front();
          q.pop();
          visited[t] = true;
          for (int j = 1; j < accounts[t].size(); ++j) {
            myset.insert(accounts[t][j]);
            for (int name : email2name[accounts[t][j]]) {
              if (!visited[name]) {
                q.push(name);
                visited[name] = true;
              }
            }
          }
        }
        vector<string> out(myset.begin(), myset.end());
        out.insert(out.begin(), accounts[i][0]);
        result.push_back(out);
      }
    }
    return result;
  }
};
