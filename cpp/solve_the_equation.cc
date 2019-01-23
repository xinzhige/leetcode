// Idea: Calculate the coefficient of x and the rest sum.
// Trick1: two pointers i and j.
// Trick2: any substring between two neighbor letters is a number or coefficient;
// Trick3: if the right pointer is larger than the left one, it is a number.
class Solution {
public:
  string solveEquation(string equation) {
    int n = equation.size();
    int left = 0;
    int right = 0;
    int sign = 1;
    int j = 0;
    for (int i = 0; i < n; ++i) {
      if (equation[i] == '+' || equation[i] == '-') {
        if (i > j) {
          right += stoi(equation.substr(j, i - j)) * sign;
        }
        j = i;
      } else if (equation[i] == 'x') {
        if (i == j || equation[i - 1] == '+') {
          left += sign;
        } else if (equation[i - 1] == '-') {
          left -= sign;
        } else {
          left += stoi(equation.substr(j, i - j)) * sign;
        }
        j = i + 1;
      } else if (equation[i] == '=') {
        if (i > j) {
          right += stoi(equation.substr(j, i - j)) * sign;
        }
        // Note the sign should be negative here.
        sign = -1;
        j = i + 1;
      }
    }
    if (j < n) {
      right += stoi(equation.substr(j)) * sign;
    }
    if (left == 0 && left == right) {
      return "Infinite solutions";
    }
    if (left == 0 && right != 0) {
      return "No solution";
    }
    return "x=" + to_string(-right / left);
  }
};
