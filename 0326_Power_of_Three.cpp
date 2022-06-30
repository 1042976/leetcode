class Solution {
public:
    //Time O(logn), Space O(1)
    // bool isPowerOfThree(int n) {
    //     if(n <= 0){
    //         return false;
    //     }
    //     while(n%3 == 0){
    //         n /= 3;
    //     }
    //     return n == 1;
    // }
    
    //Time O(1), Space O(1)
    bool isPowerOfThree(int n){
        return n >= 1 && 1162261467%n == 0;
    }
};
