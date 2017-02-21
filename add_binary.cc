class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        size_t n = a.size() > b.size() ? a.size() : b.size();
        int carry = 0;
        for (size_t i = 0; i < n; i++) {
            int ai = i < a.size() ? a[a.size() - i - 1] - '0' : 0;
            int bi = i < b.size() ? b[b.size() - i - 1] - '0' : 0;
            int val = (ai + bi + carry) % 2;
            carry = (ai + bi + carry) / 2;
            result.push_back(val + '0');
        }
        if (carry == 1) {
            result.push_back('1');
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
