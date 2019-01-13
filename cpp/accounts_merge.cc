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
    vector<int> visited(n, 0);
    for (int i = 0; i < n; ++i) {
      if (visited[i] == 0) {
        queue<int> q;
        q.push(i);
        set<string> myset;
        while (!q.empty()) {
          int t = q.front();
          q.pop();
          visited[t] = 1;
          for (int j = 1; j < accounts[t].size(); ++j) {
            myset.insert(accounts[t][j]);
            for (int name : email2name[accounts[t][j]]) {
              if (visited[name] == 0) {
                q.push(name);
                visited[name] = 1;
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


// Union find
class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    vector<int> roots(accounts.size(), 0);
    unordered_map<string, int> email2Id;
    for (int i = 0; i < accounts.size(); i++) {
      roots[i] = i;
      for (int j = 1; j < accounts[i].size(); j++) {
        if (email2Id.count(accounts[i][j]) > 0) {
          int rooti = find(roots, i);
          int roote = find(roots, email2Id[accounts[i][j]]);
          roots[rooti] = roote;
        } else {
          email2Id[accounts[i][j]] = i;
        }
      }
    }
    unordered_map<int, set<string>> id2Emails;
    for (const auto &node : email2Id) {
      int root = find(roots, node.second);
      id2Emails[root].insert(node.first);
    }
    vector<vector<string>> result;
    for (const auto &node : id2Emails) {
      vector<string> email(node.second.begin(), node.second.end());
      email.insert(email.begin(), accounts[node.first][0]);
      result.push_back(email);
    }
    return result;
  }
private:
  int find(vector<int> &roots, int id) {
    while (roots[id] != id) {
      roots[id] = roots[roots[id]];
      id = roots[id];
    }
    return id;
  }
};
