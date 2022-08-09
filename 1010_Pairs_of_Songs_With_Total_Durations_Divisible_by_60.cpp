class Solution {
public:
    //Time O(N), Space O(1)
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        int count[60];
        memset(count, 0, sizeof(count));
        for(const auto &x : time){
            int m = x%60;
            if(m == 0){
                res += count[0];
                ++count[0];
            }else{
                res += count[60-m];
                ++count[m];
            }
        }
        return res;
    }
};
