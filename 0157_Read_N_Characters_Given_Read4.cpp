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
    // // Time O(N), Space O(1)
    // int read(char *buf, int n) {
    //     int count = 0;
    //     char buf4[4];
    //     while(count < n){
    //         int readChars = read4(buf4);
    //         for(int i = 0; i < readChars; ++i){
    //             buf[count++] = buf4[i];
    //             if(count == n){
    //                 return n;
    //             }
    //         }
    //         if(readChars < 4){
    //             break;
    //         }
    //     }
    //     return count;
    // }

    // Time O(N), Space O(1)
    int read(char *buf, int n){
        int count = 0;
        while(n-count >= 4){
            int readChars = read4(buf+count);
            count += readChars;
            if(readChars < 4){
                return count;
            }
        }
        if(n-count > 0){
            char buf4[4];
            int readChars = read4(buf4);
            for(int i = 0; i < readChars; ++i){
                buf[count++] = buf4[i];
                if(count == n){
                    return n;
                }
            }
        }
        return count;
    }
};
