class Solution {
public:
    int calculate(string s) {
        int result = 0; 
        stack<int> sign;
        sign.push(1);
        sign.push(1);
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i]; 
            if (isdigit(c) {
                int num = 0; 
                for (; i < s.size() && isdigit(s[i]; ++i) {
                    num = 10 * num + s[i] - '0'; 
                }
                result += sign.top() * num;
                sign.pop();
                --i;
            } else if (c == ')') {
                sign.pop(); 
            } else if (c != ' ') {
                int curr = (c == '-' ? -1 : 1); 
                sign.push(sign.top() * curr);
            } 
        }            
        return result;
    }
};
