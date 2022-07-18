class Solution {
public:
    //Time O(N), Space O(1)
    // int findKthPositive(vector<int>& arr, int k) {
    //     int last = 0;
    //     for(size_t i = 0; i < arr.size(); ++i){
    //         int missings = arr[i]-last-1;
    //         if(k <= missings){
    //             return last+k;
    //         }else{
    //             k -= missings;
    //             last = arr[i];
    //         }       
    //     }
    //     return last+k;
    // }
    
    //binary search. Time O(logN), Space O(1)
    int findKthPositive(vector<int>& arr, int k){
        int left = 0, right = arr.size()-1;
        while(left <= right){
            int mid = left + ((right-left)>>1);
            if(arr[mid]-1-mid < k){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return left+k;
    }
};
