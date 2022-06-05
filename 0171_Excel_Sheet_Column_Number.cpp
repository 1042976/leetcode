class Solution {
public:
    //Time O(N), Space O(1)
    int titleToNumber(string columnTitle) {
        int res = 0;
        for(const auto &letter : columnTitle){
            res = res*26 + (letter-'A'+1);
        }
        return res;
    }
};
