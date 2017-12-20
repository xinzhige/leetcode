class Solution {
public:
  int repeatedStringMatch(string A, string B) {
    int result = 1;
    string S = A;
    for (; S.size() < B.size(); ++result) {
      S += A;
    }
    if (S.find(B) != string::npos) {
      return result;
    }
    S += A;
    if (S.find(B) != string::npos) {
      return result+1;
    }
    return -1;
  }
};
