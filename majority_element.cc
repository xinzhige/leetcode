class Solution {
public:
    int majorityElement(vector<int> &num) {
        int vote = num[0];
        int count = 1;
        for(int i = 1; i < num.size(); i++) {
            if(count == 0) { 
                vote = num[i]; 
                count++; 
            } else if (vote == num[i]) {
                count++;
            } else {
                count--;
            }
        }
        return vote;
    }
};