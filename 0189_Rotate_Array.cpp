class Solution {
public:
    //Time O(N), Space O(1)
    // void rotate(vector<int>& nums, int k) {
    //     int size = nums.size();
    //     k %= size;
    //     if(k == 0){
    //         return;
    //     }
    //     int r = size-1, l = r-k+1;
    //     while(l > 0){
    //         for(int i = r; i >= l; --i){
    //             if(i-k < 0){
    //                 k = i-l+1;
    //             }
    //             swap(nums[i], nums[i-k]);
    //         }
    //         l -= k;
    //         r = l+k-1;
    //     }  
    // }
    
    
    //Time O(N), Space O(1)
    // void rotate(vector<int>& nums, int k){
    //     int size = nums.size();
    //     int count = 0;
    //     for(int start = 0; count < size; ++start){
    //         int cur = start;
    //         int curVal = nums[start];
    //         int next = (cur+k)%size;
    //         int nextVal = nums[next];
    //         while(next != start){
    //             nums[next] = curVal;
    //             cur = next;
    //             next = (cur+k)%size;
    //             curVal = nextVal;
    //             nextVal = nums[next];
    //             ++count;
    //         }
    //         nums[start] = curVal;
    //         ++count;
    //     }
    // }
    
    //Time O(N), Space O(1)
    void rotate(vector<int>& nums, int k){
        k %= nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};
