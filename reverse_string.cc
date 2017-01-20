class Solution {
public:
    string reverseString(string s) {
        int begin = 0;
        int end = s.size() - 1;
        while (begin < end) {
            swap(s[begin], s[end]); 
            begin += 1;
            end -= 1;
        }
        return s;
    }
};
