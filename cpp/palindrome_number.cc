class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int div = 1;
        for (; (x / div) >= 10; div *= 10);
        while (x != 0) {
            int left_digit = x / div;
            int right_digit = x % 10;
            if (left_digit != right_digit) {
                return false;
            }
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
};
