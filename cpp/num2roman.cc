class Solution {
public:
  string intToRoman(int num) {
    string Roman = "IVXLCDM";
    string result;
    int base = 0;
    while (num > 0) { // from the low-order to high-order
      int x = num % 10;
      switch (x) {
      case 1: case 2: case 3:
	result = string(x, Roman[base]) + result;
	break;
      case 4:
	result = Roman[base+1] + result;
	result = Roman[base] + result;
	break;
      case 5:
	result = Roman[base+1] + result;
	break;
      case 6: case 7: case 8:
	result = string(x-5, Roman[base]) + result;
	result = Roman[base+1] + result;
	break;
      case 9:
	result = Roman[base+2] + result;
	result = Roman[base] + result;
	break;
      default:
	break;
      }
      base += 2;
      num /= 10;
    }
    return result;
  }
};
