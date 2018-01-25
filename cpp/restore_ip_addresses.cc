class Solution {
public:
  void dfs(string s, vector<string> &result, string ip, size_t start, size_t step) {
    if (start == s.size() && step == 4) {
      ip.resize(ip.size()-1);
      result.push_back(ip);
      return;
    }
    if (s.size() - start > (4 - step)*3 ||
	s.size() - start < (4 - step))
      return;
    int num = 0;
    for (size_t i = start; i < start + 3; ++i) {
      num = num * 10 + (s[i] - '0');
      if (num <= 255) {
	ip += s[i];
	dfs(s, result, ip+'.', i+1, step+1);
      }
      if (num == 0)
	break;
    }
  }
  vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    string ip;
    dfs(s, result, ip, 0, 0);
    return result;
  }
};
