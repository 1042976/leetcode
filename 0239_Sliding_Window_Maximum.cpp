class Solution {
public:
    //Time O(nlogk), Space O(k)
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     auto compare = [](const int &a, const int &b)->bool{
    //       return a > b;  
    //     };
    //     map<int, int, decltype(compare)> valList(compare);
    //     for(int i = 0; i < k; ++i){
    //         ++valList[nums[i]];
    //     }
    //     vector<int> res(nums.size()-k+1, 0);
    //     res[0] = valList.begin()->first;
    //     for(int i = k; i < nums.size(); ++i){
    //         ++valList[nums[i]];
    //         if(--valList[nums[i-k]] == 0){
    //             valList.erase(nums[i-k]);
    //         }
    //         res[i-k+1] = valList.begin()->first;
    //     }
    //     return res;
    // }
    
    //Time O(N), Space O(k)
    // vector<int> maxSlidingWindow(vector<int>& nums, int k){
    //     deque<int> D;
    //     for(int i = 0; i < k; ++i){
    //         while(!D.empty() && nums[D.back()] <= nums[i]){
    //             D.pop_back();
    //         }
    //         D.emplace_back(i);
    //     }
    //     vector<int> res{nums[D.front()]};
    //     for(int i = k; i < nums.size(); ++i){
    //         if(D.front() == i-k){
    //             D.pop_front();
    //         }
    //         while(!D.empty() && nums[D.back()] <= nums[i]){
    //             D.pop_back();
    //         }
    //         D.emplace_back(i);
    //         res.emplace_back(nums[D.front()]);
    //     }
    //     return res;
    // }
    
    //Time O(N), Space O(N)
//     vector<int> maxSlidingWindow(vector<int>& nums, int k){
//         vector<int> res;
//         int size = nums.size();
//         int left[size], right[size];
//         int m = size/k;
//         int r = size%k;
//         for(int i = 0; i < m; ++i){
//             int maxLeft = nums[i*k];
//             int maxRight = nums[(m-i)*k-1];
//             for(int j = 0; j < k; ++j){ 
//                 maxLeft = max(maxLeft, nums[i*k+j]);
//                 left[i*k+j] = maxLeft;
//                 maxRight = max(maxRight, nums[(m-i)*k-1-j]);
//                 right[(m-i)*k-1-j] = maxRight;
//             }
//         }
//         if(r != 0){
//             int maxLeft = nums[m*k];
//             int maxRight = nums[m*k+r-1];
//             for(int j = 0; j < r; ++j){
//                 maxLeft = max(maxLeft, nums[m*k+j]);
//                 left[m*k+j] = maxLeft;
//                 maxRight = max(maxRight, nums[m*k+r-1-j]);
//                 right[m*k+r-1-j] = maxRight;
//             }
//         }
        
//         for(int i = 0; i <= size-k; ++i){
//             res.emplace_back(max(left[i+k-1], right[i]));
//         }
//         return res;
//     }
    
    //Time O(N), Space O(N)
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        int size = nums.size();
        int left[size], right[size];
        left[0] = nums[0];
        right[size-1] = nums.back();
        int maxLeft = left[0];
        int maxRight = right[size-1];
        for(int i = 0; i < size; ++i){
            maxLeft = i%k == 0? nums[i] : max(nums[i], maxLeft);
            left[i] = maxLeft;
            int rightIdx = size-i-1;
            maxRight = (rightIdx+1)%k == 0? nums[rightIdx] : max(nums[rightIdx], maxRight);
            right[rightIdx] = maxRight;       
        }
        vector<int> res(size-k+1);
        for(int i = 0; i <= size-k; ++i){
            res[i] = max(left[i+k-1], right[i]);
        }
        return res;
    }
};
