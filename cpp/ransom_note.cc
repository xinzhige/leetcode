class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mymap;
        for (auto c : magazine) {
            if (mymap.find(c) == mymap.end()) {
                mymap[c] = 1; 
            } else {
                mymap[c] += 1; 
            } 
        }
        for (auto c : ransomNote) {
            if (mymap.find(c) == mymap.end() ||
                mymap[c] <= 0) {
                
                return false;
            } else {
                mymap[c] -= 1; 
            }
        }
        return true;
    }
};
