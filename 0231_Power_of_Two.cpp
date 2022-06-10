class Solution {
public:
    //Time O(1), Space O(1)
    bool isPowerOfTwo(int n) {
        return n > 0 && n == (n&(-n));
    }
    
    //Time O(1), Space O(1)
    // bool isPowerOfTwo(int n) {
    //     return n > 0 && (n&(n-1)) == 0;
    // }
};
