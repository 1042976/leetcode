class Solution {
public:
//     int getMed(vector<int>& nums, int l,  int r){
//         sort(nums.begin()+l, nums.begin()+r+1, [](const int &a, const int &b)->bool{
//             return a > b;
//         });
//         return nums[l+((r-l)>>1)];
//     }
//     int partition(vector<int>& nums, int l,  int r, int pivot){
//         int pivotIdx = l;
//         for(int i = l+1; i <= r; ++i){
//             if(nums[i] == pivot){
//                 pivotIdx = i;
//                 break;
//             }
//         }
//         swap(nums[pivotIdx], nums[r]);
//         int j = l;
//         int i = l;
//         for(j = l; j < r; ++j){
//             if(nums[j] > pivot){
//                 swap(nums[i++], nums[j]);
//             }
//         }
//         swap(nums[i], nums[r]);
//         return i;
//     }
//     int kthLargest(vector<int>& nums, int l, int r, int k){
//         if(k > r-l+1){
//             return nums[l];
//         }
//         int sizeOfGroups = (r-l+1)/5;
//         int rest = (r-l+1)-sizeOfGroups*5;
//         vector<int> meds;
//         for(int i = 0; i < sizeOfGroups; ++i){
//             meds.emplace_back(getMed(nums, l+i*5, l+i*5+4));
//         }
//         if(rest > 0){
//             meds.emplace_back(getMed(nums, r-rest+1, r));
//         }
//         int medOfMeds = meds.size()==1? meds[0] : kthLargest(meds, 0, meds.size()-1, meds.size()/2+1);
//         int pos = partition(nums, l, r, medOfMeds);
//         if(pos-l == k-1){
//             return nums[pos];
//         }else if(pos-l > k-1){
//             return kthLargest(nums, l, pos-1, k);
//         }else{
//             return kthLargest(nums, pos+1, r, k-(pos+1-l));
//         }
//     }
//     //Time O(n) Space O(n)
//     int findKthLargest(vector<int>& nums, int k) {
//         return kthLargest(nums, 0, nums.size()-1, k);
//     }
    //Time O(nlogk) Space O(k)
    // int findKthLargest(vector<int>& nums, int k){
    //     priority_queue<int, vector<int>, std::greater<int> > minHeap;
    //     for(int i = 0; i < k; ++i){
    //         minHeap.emplace(nums[i]);
    //     }
    //     for(int i = k; i < nums.size(); ++i){
    //         if(nums[i] > minHeap.top()){
    //             minHeap.pop();
    //             minHeap.emplace(nums[i]);
    //         }
    //     }
    //     return minHeap.top();
    // }
    
    int partition(vector<int>& nums, int l, int r){
        int idx = l+rand()%(r-l+1);
        swap(nums[idx], nums[r]);
        int i = l, j = l;
        for(j = l; j < r; ++j){
            if(nums[j] > nums[r]){
                swap(nums[i++], nums[j]);
            }
        }
        swap(nums[i], nums[r]);
        return i;
    }
    int quickSelect(vector<int>& nums, int l, int r, int k){
        int idx = partition(nums, l, r);
        if(idx-l == k-1){
            return nums[idx];
        }else if(idx-l > k-1){
            return quickSelect(nums, l, idx-1, k);
        }else{
            return quickSelect(nums, idx+1, r, k-(idx+1-l));
        }
    }
    
    //Time O(n^2) avg O(n), Space O(n)
    int findKthLargest(vector<int>& nums, int k){
        srand(time(NULL));
        return quickSelect(nums, 0, nums.size()-1, k);
    }
    
};
