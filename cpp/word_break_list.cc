class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        if (dict.size() == 0) return res;
        vector<vector<int> > spaceIdx;
        spaceIdx.resize(s.size() + 1);
        spaceIdx[0].push_back(-1);
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (spaceIdx[j].size() && dict.count(s.substr(j, i - j))) {
                    spaceIdx[i].push_back(j);
                }
            }
        }
        return backTrack(s, spaceIdx, s.size());
    }
    vector<string> backTrack(string& s, vector<vector<int> >& spaceIdx, int idx) {
        vector<string> res;
        if (idx <= 0) {
            res.push_back(""); 
            return res;
        }
        for (int i = 0; i < spaceIdx[idx].size(); i++) {
            string str = s.substr(spaceIdx[idx][i], idx - spaceIdx[idx][i]);
            vector<string> subRes = backTrack(s, spaceIdx, spaceIdx[idx][i]);
            for (int j = 0; j < subRes.size(); j++) {
                if (subRes[j] != "") {
                    subRes[j] = subRes[j] + " " + str;
                } else {
                    subRes[j] = str;
                }
                res.push_back(subRes[j]);
            }
        }
        return res;
    }
};