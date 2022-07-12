class Solution {
public:
    //Time O(logn), Space O(1)
    int trailingZeroes(int n) {
        int res = 0;
        int divisor = 5;
        while(n){
            n /= divisor;
            res += n;
        }
        return res;
    }
};
