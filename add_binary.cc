class Solution {
public:
    string addBinary(string a, string b) {
        string s("");
        long c = 0;
        long i = a.size() - 1;
	long j = b.size() - 1;
        while (i >= 0 || j >= 0 || c == 1) {
            c += i >= 0 ? a[i] - '0' : 0;
	    i -= 1;
            c += j >= 0 ? b[j] - '0' : 0;
	    j -= 1;
            s = std::to_string(c % 2) + s;
            c /= 2;
        }
        return s;
    }
};
