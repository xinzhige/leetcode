class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mymap;
        unordered_map<char, char> mymap_reversed;
        if (s.size() != t.size()) {
            return false; 
        }
        for (int i = 0; i < s.size(); i++) {
            if (mymap.find(s[i]) == mymap.end() && 
                mymap_reversed.find(t[i]) == mymap_revered.end()) { 
                mymap[s[i]] = t[i]; 
                mymap_reversed[t[i]] = s[i];
            } else if (mymap[s[i]] != t[i]) {
                    return false;  
            } 
        }
        return true;
    }
};
