class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string result = numerator < 0 ^ denominator < 0 ? "-" : "";
        long long num = numerator >= 0 ? numerator : -(long long)numerator; 
        long long den = denominator >= 0 ? denominator : -(long long)denominator;
        result += to_string(num / den);         
        long long rem = num % den;
        if (rem == 0) return result;
        result += ".";
        unordered_map<long long, size_t> flag;
        int pos = result.size();
        while (rem && flag.find(rem) == flag.end()) {
            flag[rem] = pos;
            ++pos;
            result += to_string(rem * 10 / den);
            rem = rem * 10 % den;
        }
        if (rem) {
            result += ')';
            result.insert(result.begin() + flag[rem], '(');
        }
        return result;
    }
};
