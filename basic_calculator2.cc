class Solution {
public:
    int calculate(string s) {
        stack<int> mystack;  // Store all the numbers calculated by -, * or /
        int num = 0;
        char sign = '+';  // Store the previous operator
        int s_len = s.size();
        for (int i = 0; i < s_len; ++i) {
            if (isdigit(s[i])) {
                num = 10 * num + s[i] - '0'; 
            } 
            if ((!isdigit(s[i]) && s[i] != ' ') || i == s_len - 1) {
                if (sign == '-') {
                    mystack.push(-num); 
                }
                if (sign == '+') {
                    mystack.push(num); 
                }
                int tmp = 0;
                if (sign == '*') {
                    tmp = mystack.top() * num;
                    mystack.pop();
                    mystack.push(tmp); 
                }
                if (sign == '/') {
                    tmp = mystack.top() / num; 
                    mystack.pop(); 
                    mystack.push(tmp); 
                }
                sign = s[i];
                num = 0;
            }
        }
        int result = 0;
        for (; !mystack.empty(); mystack.pop()) {
            result += mystack.top(); 
        }
        return result;
    }
};
