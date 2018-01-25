public class Solution {
    public String convertToTitle(int n) {
        String result = "";
		int remainder = 0;
		int quotient = 0;
		char tmp;
		for (int i = n; i > 0; i /= 26) {
		    quotient = i / 26;
		    remainder = i % 26;
		    if (remainder == 0) {
		        result = 'Z' + result;
		        if (quotient > 1) {
    		        tmp = (char)(quotient + 'A' - 2);
    		        result = tmp + result;
		        }
		        break;
		    } else {
		        tmp = (char)(remainder + 'A' - 1);
		    }
		    result = tmp + result;
		}
        return result; 
    }
}
