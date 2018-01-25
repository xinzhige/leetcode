class Solution {
public:
  vector<string> generatePalindromes(string s) {
    vector<string> res;
    unordered_map<char, int> mymap;
    string st = "";
    string mid = "";
    if (!can_generate_palindrome(s, st, mid, mymap)) {
      return res;
    }
    permute(st, mymap, mid, "", res);
    return res;
  }
  bool can_generate_palindrome(string &s,
                               string &st,
                               string &mid,
                               unordered_map<char, int> &mymap) {
    for (auto &c : s) {
      mymap[c] += 1;
    }
    for (auto &it : mymap) {
      if (it.second % 2 == 1) {
        mid += it.first;
      }
      it.second /= 2;
      st += string(it.second, it.first);
      if (mid.size() > 1) {
        return false;
      }
    }
    return true;
  }

  void permute(string &st,
               unordered_map<char, int> &m,
               string mid,
               string out,
               vector<string> &res) {
    if (out.size() == st.size()) {
      res.push_back(out + mid + string(out.rbegin(), out.rend()));
      return;
    }
    for (auto &it : m) {
      if (it.second > 0) {
        it.second -= 1;
        permute(st, m, mid, out + it.first, res);
        it.second += 1;
      }
    }
  }
};
