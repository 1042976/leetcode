class Solution {
public:
    //Time O(M+N), Space O(min(M, N))
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashMap;
        vector<int> res;
        if(nums1.size() > nums2.size()){
            swap(nums1, nums2);
        }
        for(const auto &x : nums1){
            ++hashMap[x];
        }
        for(const auto &x : nums2){
            if(hashMap.count(x)){
                res.emplace_back(x);
                if(--hashMap[x] == 0){
                    hashMap.erase(x);
                }
            }
        }
        return res;
    }
};
