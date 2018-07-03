// Space: O(n)
class Solution {
public:
  bool verifyPreorder(vector<int>& preorder) {
    int low = INT_MIN;
    stack<int> mystack;
    for (const auto curr : preorder) {
      if (curr < low) {
        return false; 
      } 
      while (!mystack.empty() && curr > mystack.top()) {
        low = mystack.top();
        mystack.pop(); 
      }
      mystack.push(curr);
    }
    return true;
  }
};

// Space: O(1)
class Solution {
public:
  bool verifyPreorder(vector<int>& preorder) {
    int low = INT_MIN;
    int i = -1;
    for (const auto curr : preorder) {
      if (curr < low) {
        return false; 
      } 
      while (i >= 0 && curr > preorder[i]) {
        low = preorder[i];
        i -= 1;
      }
      i += 1;
      preorder[i] = curr;
    }
    return true;
  }
};
