class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        const int n = 32;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int num0 = 0, num1 = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if (bitInKth(nums[j], i) == 0) {
                    num0 += 1; 
                } else {
                    num1 += 1; 
                } 
            } 
            sum += num0 * num1;
        }
        return sum;
    }

private:
    int bitInKth(int x, int k) {
        return (x >> k) & 1;
    }
};
