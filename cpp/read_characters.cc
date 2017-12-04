// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int result = 0;
        for (; n > 0; n -= 4) {
            int tmp = min(read4(buf), n); 
            result += tmp;
            buf += tmp;
            if (tmp < 4) {
                break; 
            }
        }
        return result;
    }
 };
