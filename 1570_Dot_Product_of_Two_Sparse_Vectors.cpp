class SparseVector {
public:
    unordered_map<int, int> hashMap;
    //Time O(n) Space O(n)
    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != 0){
                hashMap[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProductHelper(SparseVector& vec1, SparseVector& vec2){
        int res = 0;
        for(const auto &[i, n] : vec1.hashMap){
            if(vec2.hashMap.count(i)){
                res += n*vec2.hashMap[i];
            }
        }
        return res;
    }
    //Time O(k) Space O(1)
    int dotProduct(SparseVector& vec) {
        if(hashMap.size() <= vec.hashMap.size()){
            return dotProductHelper(*this, vec);
        }else{
            return dotProductHelper(vec, *this);
        }
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
