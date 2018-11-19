class Solution {
 public:
 int numMatchingSubseq(string S, vector<string>& words) {
   vector<pair<int, int>> all[128];
   int result = 0;
   for (int i = 0; i < words.size(); ++i) {
     all[words[i][0]].emplace_back(i, 1);
   }
   for (const char &c : S) {
     auto vect = all[c];
     all[c].clear();
     for (auto &it : vect) {
       if (it.second == words[it.first].size()) {
         ++result;
       } else {
         it.second++;
         all[words[it.first][it.second-1]].push_back(it);
       }
     }
   }
   return result;
  }
};
