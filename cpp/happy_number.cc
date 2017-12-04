// Hashtable
class Solution {
public:
  int square(int n) {
    int result = 0;
    int digit = 0; 
    for (; n > 0 ; n /= 10) {
      digit = n % 10; 
      result += digit * digit;	    
    }
    return result;
  } 
  
  bool isHappy(int n) {
    if (n == 1) {
      return true;	    
    } 
    unordered_map<int, bool> map;
    map[n] = true;
    while (n != 1) {
      n = square(n);
      if (map.find(n) != map.end()) {
        return false;	      
      }
      map[n] = true;
   }
   return true;
  }
};

// O(1) space
class Solution {
public:
  int square(int n) {
    int result = 0;
    int digit = 0; 
    for (; n > 0 ; n /= 10) {
      digit = n % 10; 
      result += digit * digit;	    
    }
    return result;
  } 
  
  bool isHappy(int n) {
    int slow = n;
    int fast = square(n);
    while (slow != fast) {
      slow = square(slow);
      fast=square(fast);
      fast=square(fast);
    }
    return slow == 1;
  }
};
