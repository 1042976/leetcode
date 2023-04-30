/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    char buf4[4];
    int cur, readChars = 0;
    // Time O(n), Space O(1)
    int read(char *buf, int n) {
        int count = 0;
        while(cur < readChars){
            buf[count++] = buf4[cur++];
            if(count == n){
                return n;
            }
        }
        while(count < n){
            cur = 0;
            readChars = read4(buf4);
            if(readChars == 0){
                break;
            }
            while(cur < readChars){
                buf[count++] = buf4[cur++];
                if(count == n){
                    return n;
                }
            }
        }
        return count;
    }
};
