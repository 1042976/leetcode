class Solution {
public:
    //Time O(NlogN), Space O(N)
    // long long minimalKSum(vector<int>& nums, int k){
    //     long long res = ((long long)k*(k+1))>>1;
    //     set<int> uniques(nums.begin(), nums.end());
    //     for(const auto &x : uniques){
    //         if(x <= k){
    //             res += ++k-x;
    //         }else{
    //             break;
    //         }
    //     }
    //     return res;
    // }
    
    //Time O(NlogN), Space O(logN)
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        int x = 1;
        for(int i = 0; i < nums.size(); ++i){
            if(x < nums[i]){
                int dif = nums[i]-x;
                if(k > dif){
                    res += (long long)dif*(nums[i]-1+x)>>1;
                    k -= dif;
                }else{
                    break;
                }
            }
            x = nums[i]+1;
        }
        res += (long long)k*(2*x+k-1)>>1;
        return res;
    }
    
};
