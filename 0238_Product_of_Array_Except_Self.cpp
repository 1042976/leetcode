class Solution {
public:
    //Time O(N), Space O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> product{1};
        int size = nums.size();
        for(int i = 0; i < size-1; ++i){
            product.emplace_back(product[i]*nums[i]);
        }
        int suffix = 1;
        for(int i = size-2; i >= 0; --i){
            suffix *= nums[i+1];
            product[i] *= suffix;
        }
        return product;
    }
};
