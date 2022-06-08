class Solution {
public:
    //Time O(klog(min(k, n))), Space O(min(k, n))
    // int kthSmallest(vector<vector<int>>& matrix, int k) {
    //     priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > minHeap;
    //     int n = matrix.size();
    //     for(int i = 0; i < min(k, n); ++i){
    //         minHeap.emplace(vector<int>{matrix[i][0], i, 0});
    //     }
    //     while(k > 1){
    //         vector<int> top = minHeap.top();
    //         minHeap.pop();
    //         int nextColumn = top[2]+1;
    //         if(nextColumn < n){
    //             minHeap.emplace(vector<int>{matrix[top[1]][nextColumn], top[1], nextColumn});
    //         }
    //         --k;
    //     }
    //     return minHeap.top()[0];
    // }
    
    //Time O(nlog(high-low)), Space O(1)
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];
        while(low < high){
            int mid = low + ((high-low)>>1);
            int row = n-1, col = 0;
            int lessThanMid = low, higherThanMid = high;
            int count = 0;
            while(row >= 0 & col < n){
                if(matrix[row][col] <= mid){
                    count += (row+1);
                    lessThanMid = max(matrix[row][col], lessThanMid);
                    ++col;
                }else{
                    higherThanMid = min(matrix[row][col], higherThanMid);
                    --row;
                }
            }
            if(count == k){
                return lessThanMid;
            }else if(count > k){
                high = lessThanMid;
            }else{
                low = higherThanMid;
            }
        }
        return low;
    }
    
};
