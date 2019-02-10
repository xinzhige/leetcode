// Time: O(mn), m and n are the number of queries and edges of the graph.
class Solution {
public:
  vector<double> calcEquation(vector<pair<string, string>> equations,
                              vector<double>& values,
                              vector<pair<string, string>> queries) {
    unordered_map<string, unordered_map<string, double>> graph;
    for (int i = 0; i < values.size(); ++i) {
      graph[equations[i].first][equations[i].second] = values[i];
      if (values[i] > 0.0 || values[i] < 0.0) {
        graph[equations[i].second][equations[i].first] = 1.0 / values[i];
      }
    }
    vector<double> result;
    for (const auto &q : queries) {
      unordered_set<string> visited;
      double temp = check(q.first, q.second, visited, graph);
      if (temp > 0.0 || temp < 0.0) {
        result.push_back(temp);
      } else {
        result.push_back(-1.0);
      }
    }
    return result;
  }
  double check(string dividend, string divisor, unordered_set<string> &visited,
               unordered_map<string, unordered_map<string, double>> &graph) {
    if (graph[dividend].count(divisor) > 0) {
      return graph[dividend][divisor];
    }
    for (const auto &node : graph[dividend]) {
      if (visited.count(node.first) == 0) {
        visited.insert(node.first);
        double temp = check(node.first, divisor, visited, graph);
        if (temp > 0.0 || temp < 0.0) {
          return node.second * temp;
        }
      }
    }
    return 0.0;
  }
};


/* Union-find, idea: given a query [a, b], if they share the same root, find
 * out the value of common_root/a and common_root/b, then the result is
 * (common_root/b) / (common_root/a).
 */
class UnionFind {
public:
  UnionFind(int n) {
    parents.resize(2 * n, 0);
    for (int i = 0; i < 2 * n; ++i) {
      parents[i] = i;
    }
    rank.resize(2 * n, 0);
    ratio.resize(2 * n, 1.0);
  }

  pair<int, double> find(int i) {
    double result = 1.0;
    while (i != parents[i]) {
      ratio[i] *= ratio[parents[i]];
      result *= ratio[i];
      parents[i] = parents[parents[i]];
      i = parents[i];
    }
    return {i, result};
  }

  void runUnion(int i, int j, double result) {
    auto rooti = find(i);
    auto rootj = find(j);
    if (rooti.first == rootj.first) {
      return;
    }
    if (rank[i] > rank[j]) {
      parents[rootj.first] = rooti.first;
      ratio[rootj.first] = (rooti.second * result) / rootj.second;
    } else if (rank[i] < rank[j]) {
      parents[rooti.first] = rootj.first;
      ratio[rooti.first] = rootj.second / (result * rooti.second);
    } else {
      parents[rootj.first] = rooti.first;
      ratio[rootj.first] = (rooti.second * result) / rootj.second;
      rank[i] += 1;
    }
  }

private:
  vector<int> parents;
  vector<int> rank;
  vector<double> ratio;
};

class Solution {
public:
  vector<double> calcEquation(vector<pair<string, string>>& equations,
                              vector<double>& values,
                              vector<pair<string, string>>& queries) {
    UnionFind uf(2 * equations.size());
    unordered_map<string, int> stringId;
    int j = 0;
    for (int i = 0; i < equations.size(); ++i) {
      auto p = equations[i];
      if (stringId.count(p.first) == 0) {
        stringId[p.first] = j;
        ++j;
      }
      if (stringId.count(p.second) == 0) {
        stringId[p.second] = j;
        ++j;
      }
      uf.runUnion(stringId[p.first], stringId[p.second], values[i]);
    }
    vector<double> result;
    for (const auto &q : queries) {
      if (stringId.count(q.first) == 0 || stringId.count(q.second) == 0) {
        result.push_back(-1.0);
      } else {
        auto rooti = uf.find(stringId[q.first]);
        auto rootj = uf.find(stringId[q.second]);
        if (rooti.first != rootj.first) {
          result.push_back(-1.0);
        } else {
          result.push_back(rootj.second / rooti.second);
        }
      }
    }
    return result;
  }
};
