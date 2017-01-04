class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int max1 = nums[0];
        int max2 = nums[0];
        int max3 = nums[0];
        int count = 0; 
        for (const auto &num : nums) {
            if ((num == max1 && count > 0) ||
                (num == max2 && count > 1) ||
                (num == max3 && count > 2)) {
                continue;     
            }
            if (count == 0 || num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (count == 1 || num > max2) {
                max3 = max2;
                max2 = num;
            } else if (count == 2 || num > max3) {
                max3 = num; 
            }
            count = min(count + 1, 3);
        }
        return count == 3 ? max3 : max1;
    }
};

/*
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for (const int &num : nums) {
            s.insert(num);
            if (s.size() > 3) {
                s.erase(s.begin());
            }
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin();
    }
};
*/
