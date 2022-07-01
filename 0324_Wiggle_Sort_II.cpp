class Solution {
public:
    int partition(vector<int>& nums, int left, int right){
        int idx = left + rand()%(right-left+1);
        swap(nums[idx], nums[right]);
        int i = left;
        for(int j = left; j < right; ++j){
            if(nums[j] > nums[right]){
                swap(nums[i++], nums[j]);
            }
        }
        swap(nums[i], nums[right]);  
        return i;
    }
    int quickSelect(vector<int>& nums, int left, int right, int k){
        while(left < right){
            int pos = partition(nums, left, right);
            if(pos < k-1){
                left = pos+1;
            }else if(pos > k-1){
                right = pos-1;
            }else{
                return pos;
            }
        }
        return left;
    }
    int getKthLargest(vector<int>& nums, int k){
        srand(time(NULL));
        return quickSelect(nums, 0, nums.size()-1, k);
    }
    //Time avg-O(n) worst-O(n^2), Space O(1)
    void wiggleSort(vector<int>& nums) { 
        int n = nums.size();
        int medianIdx = getKthLargest(nums, n/2);
        int median = nums[medianIdx];
        auto f = [&](int i)->int&{
            return nums[(1+2*i)%(n|1)];
        };
        int start = 0, end = n-1;
        int cur = start;
        while(cur <= end){
            int val = f(cur);
            if(val > median){
                swap(f(cur++), f(start++));
            }else if(val < median){
                swap(f(cur), f(end--));
            }else{
                ++cur;
            }
        }
    }

};
