class Solution {
public:
  vector<int> diffWaysToCompute(string input) {
    unordered_map<string, vector<int>> mymap;
    return diffWaysToComputeHelper(input, mymap);
  }

  bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*');
  }

  vector<int> diffWaysToComputeHelper(string input, unordered_map<string, vector<int>> mymap) {
    if (mymap.find(input) != mymap.end()) {
      return mymap[input];
    }
    vector<int> result;
    for (int i = 0; i < input.size(); ++i) {
      if (isOperator(input[i])) {
        vector<int> prev = diffWaysToComputeHelper(input.substr(0, i), mymap);
        vector<int> post = diffWaysToComputeHelper(input.substr(i+1), mymap);
        for (int j = 0; j < prev.size(); ++j) {
          for (int k = 0; k < post.size(); ++k) {
            if (input[i] == '+') {
              result.push_back(prev[j] + post[k]);
            } else if (input[i] == '-') {
              result.push_back(prev[j] - post[k]);
            } else {
              result.push_back(prev[j] * post[k]);
            }
          }
        }
      }
    }
    if (result.empty()) {
      result.push_back(atoi(input.c_str()));
    }
    mymap[input] = result;
    return result;
  }
};
