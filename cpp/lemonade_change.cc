class Solution {
public:
  bool lemonadeChange(vector<int>& bills) {
    int number_of_bills[2] = {0, 0};
    for (const auto & bill : bills) {
      if (bill == 5) {
        number_of_bills[0] += 1;
      } else if (bill == 10) {
        if (number_of_bills[0] > 0) {
          number_of_bills[0] -= 1;
          number_of_bills[1] += 1;
        } else {
          return false; 
        } 
      } else if (bill == 20) {
        if (number_of_bills[0] > 0 && number_of_bills[1] > 0) {
          number_of_bills[0] -= 1;
          number_of_bills[1] -= 1;
        } else if (number_of_bills[0] >= 3) {
          number_of_bills[0] -= 3; 
        } else {
          return false; 
        }
      } else {
        return false; 
      }
    }
    return true;
  }
};
