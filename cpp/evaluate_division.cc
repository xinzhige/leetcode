class Solution {
public:
  vector<double> calcEquation(vector<pair<string, string>> equations,
                              vector<double>& values,
                              vector<pair<string, string>> query) {
    unordered_map<string, unordered_map<string, double>> m;
    for (int i = 0;i < values.size(); ++i) {
      m[equations[i].first][equations[i].second] = values[i];
      if (values[i] != 0.0) {
        m[equations[i].second][equations[i].first] = 1.0 / values[i];
      }
    }
    vector<double> result;
    for (const auto &q : query) {
      unordered_set<string> s;
      double tmp = check(q.first, q.second, m, s);
      if (tmp != 0.0) {
        result.push_back(tmp);
      } else {
        result.push_back(-1.0);
      }
    }
    return result;
  }
  double check(string up, string down,
               unordered_map<string, unordered_map<string, double>> &m,
               unordered_set<string> &s) {
    if (m[up].count(down) > 0) {
      return m[up][down];
    }
    for (const auto &i : m[up]) {
      if (s.count(i.first) == 0) {
        s.insert(i.first);
        double tmp = check(i.first, down, m, s);
        if (tmp != 0) {
          return i.second * tmp;
        }
      }
    }
    return 0.0;
  }
};
