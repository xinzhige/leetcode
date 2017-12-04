class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> mymap;
        unordered_map<char, int> mymap_reversed;
        if (s.size() != t.size()) {
            return false; 
        }
        for (int i = 0; i < s.size(); i++) {
            if (mymap[s[i]] != mymap_reversed[t[i]]) {
                return false; 
            } 
            mymap[s[i]] = i + 1;
            mymap_reversed[t[i]] = i + 1;
        }
        return true;
    }
};
