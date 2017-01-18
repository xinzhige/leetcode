class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int head = 0;
        int tail = numbers.size() - 1;
        vector<int> result;
        int curr_sum = 0;
        while (head < tail) {
            curr_sum = numbers[head] + numbers[tail]; 
            if (curr_sum > target) {
                tail -= 1; 
            } else if (curr_sum < target) {
                head += 1; 
            } else {
                result.push_back(head + 1); 
                result.push_back(tail + 1); 
                break;
            } 
        }
        return result;
    }
};
