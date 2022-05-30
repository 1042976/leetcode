class Solution {
public:
    //Time O(n*2^n), Space O(n)
    // vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int> > res{vector<int>()};
    //     for(const auto &n : nums){
    //         int size = res.size();
    //         for(int i = 0; i < size; ++i){
    //             vector<int> combination(res[i].begin(), res[i].end());
    //             combination.emplace_back(n);
    //             res.emplace_back(combination);
    //         }
    //     }
    //     return res;
    // }
    
    //bit mask.
    void increaseByOne(string& binaryStr){
        int i = 0;
        while(i < binaryStr.length() && binaryStr[i] == '1'){
            binaryStr[i] = '0';
            ++i;
        }
        if(i < binaryStr.length()){
            binaryStr[i] = '1';
        }
    }
    
    //Time O(n*2^n), Space O(n)
    vector<vector<int>> subsets(vector<int>& nums){
        const int n = nums.size();
        vector<vector<int> > res;
        string binaryStr(n, '0');
        for(int i = 0; i < (int)pow(2,n); ++i){
            vector<int> combination;
            for(int j = 0; j < n; ++j){
                if(binaryStr[j] == '1'){
                    combination.emplace_back(nums[j]);
                }
            }
            res.emplace_back(combination);
            increaseByOne(binaryStr);
        }
        return res;
    }
};
