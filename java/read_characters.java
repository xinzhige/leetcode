/* The read4 API is defined in the parent class Reader4.
      int read4(char[] buf); */

public class Solution extends Reader4 {
    /**
     * @param buf Destination tmp
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    public int read(char[] buf, int n) {
        char[] tmp = new char[4];
        int hasRead = 0;
        boolean endFlag = false;
        while (!endFlag && hasRead < n) {
            int count = read4(tmp);
            endFlag = count < 4;
            count = Math.min(count, n - hasRead);
            for (int i = 0; i < count; i++) {
                buf[hasRead] = tmp[i];
                hasRead += 1;
            }
        }
        return hasRead; 
    }
}
