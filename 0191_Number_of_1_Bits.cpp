class Solution {
public:
    //Time O(1), Space O(1)
    // int hammingWeight(uint32_t n) {
    //     int count = 0;
    //     while(n != 0){
    //         if(n&1){
    //             ++count;
    //         }
    //         n >>= 1;
    //     }
    //     return count;
    // }
    
    //Time O(1), Space O(1)
    int hammingWeight(uint32_t n){
        int count = 0;
        while(n != 0){
            ++count;
            n &= (n-1);
        }
        return count;
    }
};
