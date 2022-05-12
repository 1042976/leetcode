class Solution {
public:
    //Time O(nlogn), Space O(1)
    // int minMoves2(vector<int>& nums) {
    //     int size = nums.size();
    //     sort(nums.begin(), nums.end());
    //     int median = nums[size/2];
    //     int res = 0;
    //     for(const auto &n : nums){
    //         res += abs(median-n);
    //     }
    //     return res;
    // }
    
    //Time O(n) Space O(n)
    int partition(vector<int>& nums, int l, int r, int target){
        int t = 0;
        for(t = 0; t < r; ++t){
            if(nums[t] == target){
                break;
            }
        }
        swap(nums[r], nums[t]);
        int i = l;
        for(int j = l; j < r; ++j){
            if(nums[j] < nums[r]){
                swap(nums[i++], nums[j]);
            }
        }
        swap(nums[i], nums[r]);
        return i;
    }
    
    int getMedian(vector<int>& nums, int l, int n){
        sort(nums.begin()+l, nums.begin()+l+n);
        return *(nums.begin()+l+n/2);
    }
    int getKthSmallest(vector<int>& nums, int l, int r, int k){
        if(k <= 0 || k > r-l+1){
            return nums[r];
        }
        int g = (r-l+1)/5;
        int rest = (r-l+1)-g*5;
        vector<int> meds(g, 0);
        if(rest != 0){
            meds.emplace_back(0);
        }
        for(int i = 0; i < g; ++i){
            meds[i] = getMedian(nums, l+5*i, 5);
        }
        if(rest != 0){
            meds.back() = getMedian(nums, l+5*g, rest);
        } 
        int size = meds.size();
        int medOfMeds = size==1? meds[0] : size == 2? meds[1] : getKthSmallest(meds, 0, size-1, size/2+1);
        int pos = partition(nums, l, r, medOfMeds);
        if(pos-l == k-1){
            return nums[pos];
        }else if(pos-l > k-1){
            return getKthSmallest(nums, l, pos-1, k);
        }else{
            return getKthSmallest(nums, pos+1, r, k-(pos+1-l));
        }
    }
    int minMoves2(vector<int>& nums){
        int median = getKthSmallest(nums, 0, nums.size()-1, nums.size()/2+1);
        int res = 0;
        for(const auto &x : nums){
            res += abs(median-x);
        }
        return res;
    }
};
