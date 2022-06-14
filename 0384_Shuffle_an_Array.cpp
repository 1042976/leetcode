class Solution {
public:
    vector<int> origin;
    vector<int> permutation;
    int size;
    //Time O(N), Space O(N)
    Solution(vector<int>& nums):origin(nums), permutation(nums), size(nums.size()){
        srand(time(NULL));
    }
    
    //Time O(N) Space O(1)
    vector<int> reset() {
        permutation = origin;
        return origin;
    }
    
    //Time O(N), Space O(1)
    vector<int> shuffle() {
        for(int i = 0; i < size-1; ++i){
            size_t j = i+rand()%(size-i);
            swap(permutation[i], permutation[j]);
        }
        return permutation;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
