class Solution {
public:
    //Time O(N), Space O(N)
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashSet;
        for(const auto &val : nums){
            if(hashSet.find(val) != hashSet.end()){
                return true;
            }else{
                hashSet.insert(val);
            }
        }
        return false;
    }
};
